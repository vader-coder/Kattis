#include "sim.h"
using namespace std;
void regular() {
    string tests;
    string test;
    getline(cin, tests);
    Line *line;
    int testNum = stoi(tests);
    for (int testIndex = 0; testIndex < testNum; testIndex++) {
        getline(cin, test);
        line = new Line(test);
        line->print();
        if (testIndex < (testNum - 1)) {
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