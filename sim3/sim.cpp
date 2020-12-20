#include <iostream>
using namespace std;

class Node {
    public:
        Node *next = nullptr;
        Node *previous = nullptr;
        char character;
        Node(char c) {
            this->character = c;
        }
};

class LinkedList {
    private:
        int currentSize = 0;
    public:
        Node *head = nullptr;
        Node *tail = nullptr;
        void append(char c) {
            if (this->currentSize == 0) {
                head = new Node(c);
                tail = head;
            }
            else {
                Node* current = new Node(c);
                tail->next = current;
                current->previous = tail;
                this->currentSize++;
            }
        }
        char pop() {
            char c = tail->character;
            Node *old = tail;
            tail = tail->previous;
            tail->next = nullptr;
            this->currentSize--;
            delete old;
            return c;
        }
        void join(LinkedList* endList) {
            tail->next = endList->head;
            endList->head->previous = tail;
            tail = endList->tail;
            this->currentSize += endList->size();
            //delete endList;
        }
        void print() {
            int length = this->size();
            char* output = new char[length+1];
            Node* current = this->head;
            for (int i=0; i<length; i++) {
                output[i] = current->character;
                current = current->next;
            }
            output[length] = '\n';
            //cout << output <<endl;
            printf("%s", output);
            delete[] output;
        }
        int size() {
            return this->currentSize;
        }
        //in life, may want to delete list while passing items to another one. 
        /*
        ~LinkedList() {
            //this->deleteItems();
        }*/
        void deleteItems() {
            if (this->currentSize > 0) {
                Node *current = this->head;
                Node *next = this->head;
                while (current != nullptr) {//finished with tail. 
                    next = current->next;
                    delete current;
                    current = next;
                }
            }
        }
};

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
            if (front->size() > 0) {
                front->join(mainList);
                mainList = front;
                front = new LinkedList();
            }
            current = mainList;
        }
        else if (c == '[') {
            if (front->size() > 0) {
                front->join(mainList);
                mainList = front;
                front = new LinkedList();
            }
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

//will need to modify this to accept input. 
int main() {
    int lines;
    char extra;
    char *output = nullptr;
    string line;
    LinkedList* list;
    //getline(cin, lines);
    cin >> lines;
    cin >> extra;
    for (int i=0; i<lines; i++) {
        getline(cin, line);//read in input line.
        cout << line << endl;
        list = parse(line);//read line.  
        list->print();
    }
    delete list;
    return 0;
}