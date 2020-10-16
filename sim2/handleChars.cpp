#include "sim.h"

//add char to current element
void Line::add(char &c) {
    this->currentElement->push_back(c);//add new character to iterator
    this->cursorIsAtFront = 0;//cursor isn't at front anymore.
    this->size++;
}
//does backspace on deque in current node
void Line::backspace() {
    if (this->currentElement->size() > 0) {//current element doesn't have empty deque
        this->currentElement->pop_back();//destroy last element in deque
        this->size--;
    }
    else if (!this->cursorIsAtFront && this->nodeList.size() > 1) {//deque empty but cursor at back.
        this->nodeList.pop_back();//destroy tail of list.
        this->currentElement = this->nodeList.end();//assign current element to new end.
        this->backspace();//call backspace with new, hopefully non empty element at end.
    }
    //if currently at front & current element is empty, don't do anything.
}