#include<iostream>
using namespace std;
class Node;
class List
{
	Node* head;
	Node* tail;
	public:
	List(Node* h=0):head(h),tail(h){cout<<"List ctor\n";}
	void display();
	void append(Node* n);
};

class Node{
	int info;
	Node* next;
	public:
	Node(int i):info(i),next(0){cout<<"Node ctor\n";}
	friend void List::display();
	friend void List::append(Node* n);
};

void List::display()
{
	Node* ptr=head;
	while(ptr)
	{
		cout<<ptr->info<<" ";
		ptr=ptr->next;
	}
}

void List::append(Node* n)
{
	if(!head) head=tail=n;
	else{
		tail->next=n;
		tail=tail->next;
	}
}

int main()
{
	List l;
	Node n1(1),n2(2),n3(3);
	l.append(&n1);
	l.append(&n2);
	l.append(&n3);
	l.display();
	return 0;
}
