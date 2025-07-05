#include <iostream>
using namespace std;
// stack using Array


class Stack { // creating Stack class
private:
    int size;
    int top;
    int *S;

public:
    Stack();
    Stack(int n);
    ~Stack();
    void push(int ele); 
    int pop();
    int peek(int pos);
    int isempty();
    int isfull();
    int Stacktop();
    void display();
    int length();
    void clear();
};

Stack::Stack() { // default constructor
    size = 10;
    top = -1;
    S = new int[size];
}

Stack::Stack(int n) { // parameterized constructor
    size = n;
    top = -1;
    S = new int[size];
}

Stack::~Stack() { // Stack destructor
    delete[] S;
    cout << endl << "!! STACK DELETED !!" << endl;
}

void Stack::push(int ele) { // for pushing elements
    if(top == size-1) { 
        cout << "!! STACK IS OVER FLOW !!" << endl;
    } else {
        S[++top] = ele;
    }
}

int Stack::pop() { // for poping elements
    int x = -1;
    if(top == -1) {
        cout << "!! STACK IS UNDER FLOW !!" << endl;
        return -1;
    } else {
        x = S[top--];
    }
    return x;
}

int Stack::peek(int pos) { // for finding element at given position
    int x = -1;
    if(top == -1) {
        cout << "!! STACK IS EMPTY !!" << endl;
        return -1;
    }
    if(top+1-pos < 0) {
        cout << "!! INVALID POSITION !!" << endl;
        return -1;
    } else {
        x = S[top+1-pos];
    }
    return x;
}

int Stack::isempty() { // for checking stack is empty or not
    return top==-1 ? 1 : 0;
}

int Stack::isfull() { // for checking stack is full or not
    return top!=-1 ? 1 : 0;
}

int Stack::Stacktop() { // for top element of stack
    return(top==-1) ? -1 : S[top];
}

void Stack::display() { // for displaying all element
    for(int i=0; i<=top; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

int Stack::length() {
    return top+1;
}

int main() {
    return 0; 
}