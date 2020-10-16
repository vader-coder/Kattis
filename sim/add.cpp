#include "sim.h"
using namespace std;

void Line::add(char &c) {
    if (this->right) {
        this->mainLine.push_back(c); //add to right side
        this->mainLineSize++;        //increment length of main part
    } else {                                        //push to current front queue
        this->front.at(this->frontDeques - 1).push_back(c);  //add to left side
        this->frontSizes[this->frontDeques - 1]++;  //increment index of front deque each time we add an element
    }
    this->lineSize++;  //increment length of overall line part
}