#include <iostream>
using namespace std;
// stack using Linked List


class Node { // creating node class | keeping all elements public for accessibility
public:
    int data;
    Node* next;
};

class Stack { // creating stack class | keeping top as private element, accessable only by class functions
private:
    Node* top;

public:
    Stack(){top = nullptr;}
    ~Stack();

    void push(int ele);
    int pop();
    int peek(int pos);
    int topStack();
    int isempty();
    void display();
    int length();
    void clear();
};

Stack::~Stack() { // Stack Distructor
    Node* p = top;
    while(p) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    cout << endl << "!! STACK DELETED !!" << endl;
}

void Stack::push(int ele) { // for pushing elements
    Node* t = new Node;
    t->data = ele;
    t->next = top;
    top = t;
}

int Stack::pop() { // for poping elements
    int x = -1;
    if(!top) { // condition for empty stack
        cout << "!! STACK IS EMPTY !!" << endl;
        return -1;
    }
    Node* p = new Node;
    x = top->data;
    p = top;
    top = top->next;
    delete p;
    return x;
}

int Stack::peek(int pos) { // for finding element at given position
    if(!top) { // condition for empty stack
        cout << "!! STACK IS EMPTY !!" << endl;
        return -1;
    }
    Node* p = top;
    for(int i=0; i<pos-1; i++) {
        p = p->next;
        if(!p) { // condition for give position not in stack/out of stack
            cout << "!! INVALID POSITION !!" << endl;
            return -1;
        }
    }
    return p->data;
}

int Stack::topStack() { // for top element of stack
    if(!top) {// condition for empty stack
        cout << "!! STACK IN EMPTY !!" << endl;
        return -1;
    }
    return top->data;
}

int Stack::isempty() { // for checking stack is empty or not
    return !top ? 1 : 0;
}

void Stack::display() { // for displaying all element 
    Node* p = top;
    while(p) { // display stack is reverse form || top-> 2nd ele-> 3rd ele-> ...
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack::length() { // for finding the length of stack
    if(!top){return 0;} // condition for empty stack
    Node* p = top;
    int len = 0;
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

void Stack::clear() { // for deleting all elements of the Stack | top->NULL
    if(!top){return;} // conditiion for empty Stack
    Node* p = top;
    while(top) {
        top = top->next;
        delete p;
    }
}

int main() {
    return 0;
}

