// main.cpp -- take 1
#include <UnitTest++/UnitTest++.h>
#include "sim.h"

TEST(Basic){
  string line = "aaa<bb<c";
  LinkedList* list = parse(line);//read line.
  //cout << "head: " << list->head->character << " tail:" << list->tail->character << endl;
  char* ans = list->getStr();
  string str(ans);
  //cout << str<<endl;
  CHECK_EQUAL("aabc", str);
  list->deleteNodes();//must be an easier way to do this.
  delete list;
}
TEST(Sample1) {
  string line = "my ]]name]] is]] steva<en]<n halim]]]]]";
  LinkedList* list = parse(line);
  char* ans = list->getStr();
  string str(ans);
  //cout << str<<endl;
  CHECK_EQUAL("my name is steven halim", str);
  list->deleteNodes();
  delete list;
}

TEST(Sample2) {
  string line = "<<hate<<<<loves[steva<en ] cs2040c< and also cs2040c";
  LinkedList* list = parse(line);
  char* ans = list->getStr();
  string str(ans);
  //cout << str<<endl;
  CHECK_EQUAL("steven loves cs2040 and also cs2040c", str);
  list->deleteNodes();
  delete list;
}

TEST(OpenClose) {
  string line = "calvin[] is my bf";
  LinkedList* list = parse(line);
  char* ans = list->getStr();
  string str(ans);
  //cout << str<<endl;
  CHECK_EQUAL("calvin is my bf", str);
  list->deleteNodes();
  delete list;
}

TEST(Empty) {
  string line = "";
  LinkedList* list = parse(line);
  char* ans = list->getStr();
  string str(ans);
  list->deleteNodes();
  delete list;

  line = "<";
  list = parse(line);
  ans = list->getStr();
  string str1(ans);
  list->deleteNodes();
  delete list;

  line = "[]";
  list = parse(line);
  ans = list->getStr();
  string str2(ans);
  list->deleteNodes();
  delete list;

  CHECK_EQUAL("", str);
  CHECK_EQUAL("", str1);
  CHECK_EQUAL("", str2);
}
//1000000
TEST(LongLine) {
  char* test = new char[1000001];
  for (int i=0; i<1000000; i++) {
    test[i] = 'a';
  }
  test[1000000] = '\n';
  string line(test);
  LinkedList* list = parse(line);
  char* ans = list->getStr();
  string str(ans);
  //cout << str<<endl;
  CHECK_EQUAL(line, str);
  list->deleteNodes();
  delete list;
  delete test;
}

TEST(EmptyDifferenceBetweenFrontAndMain) {
  string line = "[a]bc[d";
  LinkedList* list = parse(line);
  char* ans = list->getStr();
  string str(ans);
  //cout << str<<endl;
  CHECK_EQUAL("dabc", str);
  list->deleteNodes();
  delete list;

  line = "a[]bc";
  list = parse(line);
  ans = list->getStr();
  string str1(ans);
  //cout << str<<endl;
  CHECK_EQUAL("abc", str1);
  list->deleteNodes();
  delete list;
}

int main(int, const char *[]) {
   return UnitTest::RunAllTests();
}
