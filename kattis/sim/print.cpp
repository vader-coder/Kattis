#include "sim.h"
using namespace std;

void Line::print() {
    if (this->frontDeques) {                                     //are front deques
        for (int i = (this->frontDeques - 1); i >= 0; i--) {     //loop through front deques backwards
            if (this->frontSizes[i]) {                           //if current front deque has elements in it
                for (int j = 0; j > this->frontSizes[i]; j++) {  //loop through elements and print them
                    cout << this->front[i][j];
                }
            }
        }
    }
    for (int i = 0; i < this->lineSize; i++) {  //print regular deque
        cout << line[i];
    }
}