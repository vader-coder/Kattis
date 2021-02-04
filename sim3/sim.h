#include <iostream>
#include <string>
using namespace std;
#define NULL_TERMINATOR '\0'

class Node {
    public:
      //previous & next always need to point to the previous and next nodes in the list
        Node *next = nullptr;
        Node *previous = nullptr;
        char character;
        Node(char c) {
            this->character = c;
        }
};

class LinkedList {
    private:
        int currentSize = 0;//invariant to track size of linked list.
        char* strVersion = nullptr;
    public:
        Node *head = nullptr;
        Node *tail = nullptr;
        void append(char c) {
            if (this->currentSize == 0) {
                head = new Node(c);
                tail = head;
            }
            else {//currentSize > 0
                Node* current = new Node(c);
                tail->next = current;
                current->previous = tail;
                tail = current;
            }
            this->currentSize++;
        }
        char pop() {//don't do if only 1.
          if (this->currentSize > 1) {
            char c = tail->character;
            Node *old = tail;
            tail = tail->previous;
            tail->next = nullptr;
            this->currentSize--;
            delete old;
            return c;
          } else if (this->currentSize == 1) {
            char c = tail->character;
            Node *old = tail;
            head = nullptr;
            tail = nullptr;
            this->currentSize--;
            delete old;
            return c;
          } else {
            throw runtime_error("You popped from an empty list.");
          }
        }
        void join(LinkedList* endList) {
            tail->next = endList->head;
            endList->head->previous = tail;
            tail = endList->tail;
            this->currentSize += endList->size();
            delete endList;//don't delete the items.
        }
        void print() {
          this->mkStr();
          char* output = this->getStr();
          printf("%s\n", output);
        }
        void mkStr() {
          if (this->strVersion != nullptr) {
            delete[] strVersion;
          }
          int length = this->size();
          this->strVersion = new char[length+1];
          Node* current = this->head;
          for (int i=0; i<length; i++) {
              this->strVersion[i] = current->character;
              current = current->next;
          }
          this->strVersion[length] = NULL_TERMINATOR;
        }
        char* getStr() {//if exits, get it.
          if (this->strVersion == nullptr) {
              this->mkStr();
          }
          return this->strVersion;
        }
        int size() {
            return this->currentSize;
        }
        //in life, may want to delete list while passing items to another one.
        ~LinkedList() {
            this->deleteCharStr();
        }
        //call when want to delete all the nodes used as data.
        void deleteNodes() {
          if (this->currentSize > 0) {
              Node *current = this->head;
              Node *next;
              while (current != nullptr) {//finished with tail.
                  next = current->next;
                  delete current;
                  current = next;
              }
          }
          this->currentSize = 0;
        }
        void deleteCharStr() {
          if (this->strVersion != nullptr) {
            delete[] strVersion;
            strVersion = nullptr;
          }
        }
};

void joinHandler(LinkedList** mainList, LinkedList** front) {
  int frontSize = (*front)->size();
  int mainSize = (*mainList)->size();
  if (frontSize > 0 && mainSize > 0) {//both not empty
    (*front)->join((*mainList));
    *mainList = *front;
    *front = new LinkedList();
  } else if (frontSize > 0) {//main empty, front not.
    *mainList = *front;
    *front = new LinkedList();
  }
}

LinkedList* parse(const string& str) {
    LinkedList* front = new LinkedList();
    LinkedList* mainList = new LinkedList();
    LinkedList* current = mainList;
    for (char c : str) {
        if (c == '<') {
            if (current->size() > 0) {
                current->pop();
            }
        }
        else if (c == ']') {
          joinHandler(&mainList, &front);
          current = mainList;
        }
        else if (c == '[') {
          joinHandler(&mainList, &front);
          current = front;
        }
        else {
            current->append(c);
        }
    }
    if (front->size() > 0) {
        front->join(mainList);
        mainList = front;
    }
    else {
        delete front;//check for memory leaks.
    }
    return mainList;
}
