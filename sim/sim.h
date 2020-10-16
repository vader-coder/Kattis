#include <iostream>
#include <string>
#include <deque>
#include <vector>

//idea is to give illusion there is one line, when really there are several
class Line {
   public:
    Line(std::string &test);
    void print();
   private:
    std::deque<char> mainLine;           //main line
    std::vector<std::deque<char>> front;  //vector of deques that are at the front
    std::vector<int> frontSizes;     //vector to sizes of deques in front
    std::deque<char> *currentFront = nullptr;  //pointer to current front queue
    int frontDeques = 0;
    int mainLineSize = 0; //main (that is, right) line size
    int lineSize = 0; //output line size
    int right = 1;  //at right by default.
    void handle(char &c);//handle one character in a string.
    void add(char &c);//add a character to the line data structure
    void remove();//remove character from line data structure
};