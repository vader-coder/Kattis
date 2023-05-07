#include "sim.h"

Line::Line(string &s) {
    this->nodeList.push_back(deque<char>());//push empty deque to serve as beginnig and tail.
    this->currentElement = this->nodeList.begin();//assign current element to first one.
    for (char& c : s) {
        if (c == '<') {//do a backspace
            this->backspace();
        }
        else if (c == '[') {//move cursor to front
            this->front();
        }
        else if (c == ']') {//move cursor to back
            this->back();
        }
        else {//if it is any other character, add it to the line
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