//class definition:

#include <deque>
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Line {
   public:
    Line(string& s);  //construct the line
    ~Line();
    void print();  //start from head, go to tail.
    void buildOutputCharPtr();
    void add(char& c);                 //add char to current element
    void backspace();                  //does backspace on current que.
    void front();                      //put cursor to back
    void back();                       //put cursor to front
    int strcomp(char* s, int length);  //compare content to string
    int strcomp(string s);
    char* getCharPtr() {
        if (this->printWasCalled) {
            return this->characters;
        }
        else {
            cout <<"ERROR: getCharPtr() called before char pointer allocated."<<endl;
        }
    }
   private:
    list<deque<char>> nodeList;
    list<deque<char>>::iterator currentElement;  //set to first element by default
    int cursorIsAtFront = 0;                     //either at front or at back
    char* characters;                            //to be built
    int size = 0;
    int printWasCalled = 0;
};

//test
//we must change this so we take in input, calculate answers, then print them, not print as answer.
void kattis() {
    string tests;
    string test;
    getline(cin, tests);
    Line* line;
    int testNum = stoi(tests);
    Line** lines = new Line*[testNum];
    //Line lines[testNum];
    //calculate output 
    for (int testIndex = 0; testIndex < testNum; testIndex++) {
        getline(cin, test);
        line = new Line(test);  //    Line* list = new Line(input);
        //Line line(test);
        line->buildOutputCharPtr();
        lines[testIndex] = line;
    }
    //print output
    for (int testIndex = 0; testIndex < testNum; testIndex++) {
        lines[testIndex]->print();
        if (testIndex < (testNum - 1)) {
            cout << endl;
        }
        delete lines[testIndex];
        lines[testIndex] = nullptr;
    }
    //line = nullptr; doulbe free, possibly unnecessary
    delete lines;
    lines = nullptr;
}
int main() {
    kattis();
    return 0;
}

Line::Line(string& s) {
    this->nodeList.push_back(deque<char>());        //push empty deque to serve as beginnig and tail.
    this->currentElement = this->nodeList.begin();  //assign current element to first one.
    for (char& c : s) {
        if (c == '<') {  //do a backspace
            this->backspace();
        } else if (c == '[') {  //move cursor to front
            this->front();
        } else if (c == ']') {  //move cursor to back
            this->back();
        } else {  //if it is any other character, add it to the line
            this->add(c);
        }
    }
}
Line::~Line() {
    if (this->printWasCalled) {
        delete[] this->characters;
        this->characters = nullptr;
    }
}

//add char to current element
void Line::add(char& c) {
    this->currentElement->push_back(c);  //add new character to iterator
    this->cursorIsAtFront = 0;           //cursor isn't at front anymore.
    this->size++;
}
//does backspace on deque in current node
void Line::backspace() {
    if (this->currentElement->size() > 0) {  //current element doesn't have empty deque
        this->currentElement->pop_back();    //destroy last element in deque
        this->size--;
    } else if (!this->cursorIsAtFront && this->nodeList.size() > 1) {  //deque empty but cursor at back.
        this->nodeList.pop_back();                                     //destroy tail of list.
        this->currentElement = this->nodeList.end();                   //assign current element to new end.
        this->backspace();                                             //call backspace with new, hopefully non empty element at end.
    }
    //if currently at front & current element is empty, don't do anything.
}

//print items
//TODO: check if was built already.
void Line::print() {  //start from head, go to tail.
    //list<deque<char>>::iterator node;
    //deque<char>::iterator character;
    if (!this->printWasCalled) {     //char* characters was not built yet
        this->buildOutputCharPtr();  //build it.
    }
    cout << this->characters;
}
void Line::buildOutputCharPtr() {                 //build char pointer containing output string
    this->characters = new char[this->size + 1];  //one extra space for the null terminator
    int charIndex = 0;
    for (deque<char> node : this->nodeList) {  //node = this->nodeList.begin(); node != this->nodeList.end(); node++) {//iterate through linked list
        for (char character : node) {          // = node->begin(); character != node->end(); character++) {//iterate through deque
            this->characters[charIndex] = character;
            charIndex++;
        }
    }
    this->characters[this->size] = '\0';  //last entry is null terminator
    this->printWasCalled = 1;             //change to characters were built
}
//compare content to string
int Line::strcomp(char* s, int length) {  //compare content to string
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

//put cursor in front
//change iterator to beginning of list, put flag to not at front
void Line::front() {
    if (this->nodeList.begin()->size()) {          //if element at front not empty
        this->nodeList.push_front(deque<char>());  //create new empty element at front            }
    }
    this->currentElement = this->nodeList.begin();  //update current element to point at front
    this->cursorIsAtFront = 1;
}
//put cursor in back
//change iterator to end of list, put flag to not at front
void Line::back() {
    if (this->nodeList.size()) {
        this->currentElement = --this->nodeList.end();
    } else {  //create new element, which is both end and beginning but we will treat it as end.
        this->nodeList.push_back(deque<char>());
        this->currentElement = this->nodeList.begin();
    }
    this->cursorIsAtFront = 0;  //should this be in the if statement?
}