#include <deque>
#include <list>
#include <string>
using namespace std;

class Line {
    public:
        Line(string &s);//construct the line
        ~Line();
        void print();//start from head, go to tail.
        void buildOutputCharPtr();
        void add(char &c);//add char to current element
        void backspace();//does backspace on current que.
        void front();//put cursor to back
        void back();//put cursor to front
        int strcomp(char* s, int length);//compare content to string
        int strcomp(string s);
    private:
        list<deque<char>> nodeList;
        list<deque<char>>::iterator currentElement;//set to first element by default
        int cursorIsAtFront = 0;//either at front or at back
        char* characters;//to be built
        int size = 0;
        int printWasCalled = 0;
};