#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

#define STACKSIZE 100

template <class T>
class Stack {
    int top;
    T* nodes;
public:
    Stack();      //default constructor
    int empty(void);
    void push(T&);
    T pop(void);
    T pop(int&);
    ~Stack();   //default destructor
};

template <class T> Stack<T>::Stack() {
    top = -1;
    nodes = new T[STACKSIZE];
};

template <class T> Stack<T>::~Stack() {
    delete nodes;
};

template <class T> int Stack<T>::empty(void) {
    return top==-1;
};

template <class T> void Stack<T>::push(T& j) {
    if(top == STACKSIZE) {
        cout<< "Stack overflow\n";
        return;
    }
    nodes[++top] = j;
};

template <class T> T Stack<T>::pop(void) {
    T p;
    if(empty()) {
        cout<< "Stack underflow"<<endl;
        return p;
    }
    p = nodes[top--];
    return p;
};

template <class T> T Stack<T>::pop(int& und) {
    T p;
    if(empty() ) {
        und = 1;
        return p;
    }
    und = 0;
    p = nodes[top--];
    return p;
};

#endif
