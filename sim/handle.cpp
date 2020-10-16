#include "sim.h"
using namespace std;

void Line::handle(char &c) {
    if (c == '<') {//backspace
        this->remove();
    } else if (c == ']') {
        this->right = 1;//set flag so adding to right side of line
    } else if (c == '[') {
        this->right = 0;//set right to false so adding to left side of line
        this->frontDeques++;//increment number of front deques by one
        this->front.push_back(deque<char>());//push front deque to vector of fronts
        this->frontSizes.push_back(0);//push index with length of front deque to vector
        //this->currentFront = &this->front.at(this->frontDeques - 1);
    } else {
        this->add(c);//call function to add character to whichever side it should be added to
    }
}