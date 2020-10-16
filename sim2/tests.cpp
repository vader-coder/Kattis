#include "sim.h"
#include <string>
#include <iostream>
//works
void append() {
    string input = "I";
    Line* list = new Line(input);
    string str = "want this to work, please.";
    for (char& c:str) {
        list->add(c);
    }
    list->print();
    cout<<endl;
}
//error was that you forgot to add else statement to add any other character in the constructor
//most 'bugs' seem to be me just forgetting stuff.
void backspace() {
    string input = "I don't<<<<<";
    Line* list = new Line(input);
    string str = " want this to work, too.";
    for (char& c : str) {
        list->add(c);
    }
    list->print();
    cout <<endl;
}
void backspace1() {
    string input = "stuff<<<<<<<<<<This worked.";
    Line* list = new Line(input);
    list->print();
    delete list;
}
void backAndForth() {//works now
    string input = "to [love ]type.[I ";//should read 'I love to type'
    Line* list = new Line(input);
    list->print();
    delete list;
}
void thousands() {
    string input = "";
    int length = 1000;
    for (int i = 0; i < length; i++) {
        input +=  "a";
    }
    Line* list = new Line(input);
    list->print();
    if (list->strcomp(input)) {
        cout << "a " << length << " worked." << endl;
    }
    else {
        cout << "a " << length << " didn't work." << endl;
    }
    delete list;
}
void thousandsToEnd() {//10^3 elements with some ] and < works.
    string input = "";
    int length = 1000;
    for (int i = 0; i < 300; i++) {
        input += "a";
    }
    input += "e<]";//303
    for (int i = 0; i < 300; i++) {
        input += "b";
    }
    input += "e<]";//606
    for (int i = 0; i < 300; i++) {
        input += "c";
    }
    input += "e<]";//909. 1000 - 900. 9 chars will not be in output.
    for (int i = 0; i < 100; i++) {
        input += "d";
    }
    string check = "";
    for (int i = 0; i < length; i++) {
        if (i < 300) {
            check += "a";
        }
        else if (i < 600) {
            check += "b";
        }
        else if (i < 900) {
            check += "c";
        }
        else {
            check += "d";
        }
    }
    Line* list = new Line(input);
    //list->print();
    list->buildOutputCharPtr();
    if (list->strcomp(check)) {
        cout << endl << "abcd " << length << " worked." << endl;
    }
    else {
        cout << endl << "abcd " << length << " didn't work." << endl;
    }
    delete list;
}
void backCharsOneK() {
    string input = "";
    int length = 1000;
    for (int i = 0; i < 100; i++) {
        input += "d";
    }
    input += "e<[";//303
    for (int i = 0; i < 300; i++) {
        input += "c";
    }
    input += "e<[";//606
    for (int i = 0; i < 300; i++) {
        input += "b";
    }
    input += "e<[";//909. 1000 - 900. 9 chars will not be in output.
    for (int i = 0; i < 300; i++) {
        input += "a";
    }
    string check = "";
    for (int i = 0; i < length; i++) {
        if (i < 300) {
            check += "a";
        }
        else if (i < 600) {
            check += "b";
        }
        else if (i < 900) {
            check += "c";
        }
        else {
            check += "d";
        }
    }
    Line* list = new Line(input);
    //list->print();
    list->buildOutputCharPtr();
    if (list->strcomp(check)) {
        cout << endl << "abcd " << length << " worked." << endl;
    }
    else {
        cout << endl << "abcd " << length << " didn't work." << endl;
    }
    delete list;
}
void tenToTheSixth() {
    string input = "";
    int length = 1000000;
    for (int i = 0; i < length; i++) {
        input += "a";
    }
    Line* list = new Line(input);
    list->buildOutputCharPtr();
    if (list->strcomp(input)) {
        cout << "a " << length << " worked." << endl;
    }
    else {
        cout << "a " << length << " didn't work." << endl;
    }
    delete list;
}
void kattis() {
    string tests;
    string test;
    getline(cin, tests);
    Line* line;
    int testNum = stoi(tests);
    for (int testIndex = 0; testIndex < testNum; testIndex++) {
        getline(cin, test);
        line = new Line(test);//    Line* list = new Line(input);
        line->print();
        if (testIndex < (testNum - 1)) {
            cout << endl;
        }
        delete line;
        line = nullptr;
    }
}
int main() {
    /*cout << "started" << endl;
    //backspace(); passed
    //backspace1(); passed 
    //backAndForth(); passed
    //thousands(); passed
    for (int i = 0; i < 10; i++) {
        thousandsToEnd();//works
        backCharsOneK();
    }
    for (int i = 0; i < 4; i++) {
        tenToTheSixth();
    }
    cout << "finished" <<endl;*/
    kattis();
    return 0;
}