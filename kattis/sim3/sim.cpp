#include "sim.h"

//will need to modify this to accept input.
int main() {
  char extra;
  char *output = nullptr;
  string line, lineNum;
  LinkedList* list;
  getline(cin, lineNum);//# from first line
  int lines = stoi(lineNum, nullptr);
  /*cin >> lines;
  cin >> extra;*/
  for (int i=0; i<lines; i++) {
    getline(cin, line);//read in input line.
    //cout << line << endl;
    list = parse(line);//read line.
    list->print();
    list->deleteNodes();
    delete list;
  }
  return 0;
}
