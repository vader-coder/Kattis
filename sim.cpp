#include <iostream>
using namespace std;

class LinkedList {
    public:
        Node *head;
        Node *tail;
        int size;
        void append(char c) {
            Node* current = new Node(c);
            tail->next = current;
            current->next = tail;
        }
        char pop() {
            char c = tail->character;
            Node *old = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete old;
            return c;
        }
        void join(LinkedList* endList) {
            tail->next = endList->head;
            endList->head->previous = tail;
            tail = endList->tail;
            size += endList->size;
        }
        void print() {
            char *output = new char[list.size+1]
            Node *current = this->head;
            for (int i=0; i<list.size; i++) {
                output[i] = current->character;
                current = current->next;
            }
            output[this->size+1] = '\n';
            cout << output <<endl;
            delete output;
        }
}

class Node {
    public:
        Node *next = nullptr;
        Node *previous = nullptr;
        char character;
        Node(char c) {
            this->character = c;
        }
}

LinkedList* parse(string* str):
    LinkedList* front = new LinkedList();
    LinkedList* main = new LinkedList();
    LinkedList* current = main
    for (char c in str) {
        if (c == '<') {
            if current->size > 0 {
                current->pop()
            }
        }
        else if (c == ']') {
            if (front->size > 0) {
                front->join(main);
                main = front;
                front = new LinkedList();
            }
            current = main;
        }
        else if (c == '[') {
            if (front->size > 0) {
                front->join(main);
                main = front;
                front = new LinkedList();
            }
            current = front;
        }
        else {
            current->append(c);
        }
    }
    if (front->size > 0) {
        front->join(main);
        main = front;
    }
    else {
        delete front;//check for memory leaks.
    }
    return main;
}

//will need to modify this to accept input. 
int main() {
    LinkedList list;// = LinkedList();
    //stuff. 
    char *output = new char[list.size+1]
    Node *current = list.head;
    for (int i=0; i<list.size; i++) {
        output[i] = current->character;
        current = current->next;
    }
    output[list.size+1] = '\n';
    cout << output <<endl;;
    return 0;
}