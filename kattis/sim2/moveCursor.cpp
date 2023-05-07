#include "sim.h"

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
    }
    else {//create new element, which is both end and beginning but we will treat it as end.
        this->nodeList.push_back(deque<char>());
        this->currentElement = this->nodeList.begin();
    }
    this->cursorIsAtFront = 0;//should this be in the if statement?
}