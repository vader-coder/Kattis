#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

class Line {
    public:
        Line(string &test) {
            int count = 0;
            int testSize = test.size();
            for (char &c: test) {
                this->handle(c);               
            }
        }
        void print() {
            if (this->frontDeques) {//are front deques
                for (int i=(this->frontDeques-1); i>=0; i--) {//loop through front deques backwards
                    if (this->frontSizes[i]) {//if current front deque has elements in it
                        for (int j=0; j>this->frontSizes[i]; j++) {//loop through elements and print them
                            cout << this->front[i][j];
                        }
                    }
                }
            }
            for (int i=0; i<this->lineSize; i++) {//print regular deque
                cout << line[i];
            }
        }
    private:
        deque<char>line;//main line
        vector<deque<char>>front;//vector of deques that are at the front
        vector<int>frontSizes;//vector to sizes of deques in front
        deque<char>*currentFront;//pointer to current front queue
        int frontDeques = 0;
        int lineSize = 0;
        int right = 1;//at right by default.
        void handle(char &c) {
            if (c == '<') {
                this->remove();
            }
            else if (c == ']') {
                this->right = 1;
            }
            else if (c == '[') {
                this->right = 0;
                this->frontDeques++;
                this->front.push_back(deque<char>());
                this->frontSizes.push_back(0);
                *(this->currentFront) = this->front.at(this->frontDeques-1);
            }
            else {
                this->add(c);
            }
        }
        void add(char &c) {
            if (this->right) {
                this->line.push_back(c);//add to right side
                this->lineSize++;//increment length of main part
            }
            else {//push to current front queue
                this->currentFront->push_back(c);//add to left side
                this->frontSizes[this->frontDeques-1]++;//increment index of front deque each time we add an element
            }
        }
        void remove() {
            if (this->lineSize > 0) {//check to make sure line is not zero
                if (this->right) {
                    this->line.pop_back();//pop from right side.
                    this->lineSize--;
                }
                else {
                    this->currentFront->pop_back();//add to left side
                    this->frontSizes[this->frontDeques-1]--;//decrement index of front deque each time we add an element
                }                        
            }
        }
};
void regular() {
    string tests;
    string test;
    getline(cin, tests);
    Line *line;
    int testNum = stoi(tests);
    for (int testIndex=0; testIndex<testNum; testIndex++) {
        getline(cin, test);
        line = new Line(test);
        line->print();
        if (testIndex < (testNum-1)) {
            cout << endl;
        }
        delete line;
        line = nullptr;
    }
}
void test(string str) {
    Line *line;
    line = new Line(str);
    line->print();
    delete line;
    line = nullptr;
}
int main() {
    test("<<hate<<<<loves[steva<en");
    return 0;
}