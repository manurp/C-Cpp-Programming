#ifndef List_
#define List_
#include<iostream>
using namespace std;

class List {
private:
    struct node
    {
        int info;
        node* next;
    };
    typedef node* nodeptr;
    nodeptr listptr;

public:
    List();
    ~List();
    bool emptyList();
    void insertAfter(int, int);
    void push(int);
    void delete_(int);
    int pop();
};

List::List() {
    listptr = 0;
}

List::~List() {
    nodeptr p,q;
    if(emptyList())
        return;
    for(p=listptr, q=p->next; p!=0; p=q ,q=p->next)
        delete p;
}

bool List::emptyList() {
    return listptr==0;
}

void List::insertAfter(int oldValue, int newValue) {
    nodeptr p, q;
    for(p=listptr; p!=0 && p->info != oldValue; p = p->next)
        ;
    if(p==0) {
        cout << "ERROR: value sought is not on the list.\n";
        return;
        //error("ERROR: value sought is not on the list.");
    }
    q = new node;
    q->info = newValue;
    q->next = p->next;
    p->next = q;
}

void List::push(int newValue) {
    nodeptr p;
    p = new node;
    p->info = newValue;
    p->next = listptr;
    listptr = p;
}

void List::delete_(int oldValue) {
    nodeptr p, q;
    for(q=0, p=listptr; p!=0 && p->info!=oldValue;q=p, p=p->next)
        ;
    if(p==0) {
        cout << "ERROR: value sought is not on the list." <<endl;
        return;
        //error("ERROR: value sought is not on the list.");
    }
    if(q==0)
        listptr=p->next;
    else
        q->next = p->next;
    delete p;
}

int List::pop() {
    nodeptr p;
    int x;
    if(emptyList()) {
        cout << "ERROR: the list is empty. "<<endl;
        return -1;
        //error("ERROR: the list is empty. ");
    }
    p = listptr;
    listptr = p->next;
    x = p->info;
    delete p;
    return x;
}

#endif
