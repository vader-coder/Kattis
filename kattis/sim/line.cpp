#include "sim.h"
using namespace std;

Line::Line(string &test) {
    int count = 0;
    int testSize = test.size();
    for (char &c : test) {
        this->handle(c);
    }
}