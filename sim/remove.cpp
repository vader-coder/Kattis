#include "sim.h"
using namespace std;

void Line::remove() {
    if (this->lineSize > 0) {  //check to make sure line is not zero
        if (this->right) {
            this->mainLine.pop_back(); //pop from right side.
            this->mainLineSize--;//number of characters in line decreases
            //error: only decrementing lineSize for main line.
        } else {//removing from left
            if (this->frontSizes[this->frontDeques-1]) {//if size > 0
                this->front.at(this->frontDeques - 1).pop_back();  //add to left side
                this->frontSizes[this->frontDeques - 1]--;         //decrement size of front deque each time we add an element
            }
            else {//otherwise, pop deque
                this->front.pop_back();
                this->frontDeques--;
                this->frontSizes.pop_back();
            }
        }
        this->lineSize--;
    }
}