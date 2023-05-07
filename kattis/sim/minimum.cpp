#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Line {
   public:
    Line() {
        this->frontDeques++;
        this->front.push_back(deque<char>());
        this->frontSizes.push_back(0);
        this->currentFront = &this->front.at(this->frontDeques - 1);
    }
   private:
    deque<char> line;           //main line
    vector<deque<char>> front;  //vector of deques that are at the front
    vector<int> frontSizes;     //vector to sizes of deques in front
    deque<char> *currentFront;  //pointer to current front queue
    int frontDeques = 0;
    int lineSize = 0;
    int right = 1;  //at right by default.
};
int main() {
    Line *line;
    line = new Line();
    delete line;
    line = nullptr;
    return 0;
}