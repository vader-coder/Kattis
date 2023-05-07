#include "sim.h"
#include <iostream>

//print items
//TODO: check if was built already.
void Line::print()  {  //start from head, go to tail.
    //list<deque<char>>::iterator node;
    //deque<char>::iterator character;
    if (!this->printWasCalled) {//char* characters was not built yet
        this->buildOutputCharPtr();//build it.
    }
    cout << this->characters << endl;
}
void Line::buildOutputCharPtr() {//build char pointer containing output string
    this->characters = new char[this->size+1];//one extra space for the null terminator
    int charIndex = 0;
    for (deque<char>node : this->nodeList) {//node = this->nodeList.begin(); node != this->nodeList.end(); node++) {//iterate through linked list
        for (char character : node) {// = node->begin(); character != node->end(); character++) {//iterate through deque
            this->characters[charIndex] = character;
            charIndex++;
        }
    }
    this->characters[this->size] = '\0';//last entry is null terminator
    this->printWasCalled = 1;//change to characters were built
}
//compare content to string
int Line::strcomp(char* s, int length) {//compare content to string
    if (length != this->size || !this->printWasCalled) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (this->characters[i] != s[i]) {
            return 0;
        }
    }
    return 1;
}
int Line::strcomp(string s) {
    int length = s.size();
    if (length != this->size || !this->printWasCalled) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (this->characters[i] != s[i]) {
            return 0;
        }
    }
    return 1;
}