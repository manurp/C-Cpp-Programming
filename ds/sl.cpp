#include<iostream>
#include<cstdlib>
using namespace std;

/* Node declaration */
struct node
{
	int info;
	struct node* next;
}*start;

/* Class declaration */
class single_list
{
	public:
		node* create_node(int);
		void insert_begin(int);
		void insert_end(int);
		void insert_pos(int,int);
		int delete_first();
		int delete_last();
		int search(int);
		void display();
		int isEmpty();
		int count();
		void reverse();
		void delete_ele(int);
		single_list()
		{
			start = NULL;
		}
};

/* main function */
int main()
{
	int ch,node,element,position;
	single_list sl;
	//start = NULL;
	while(1)
	{
		cout<<endl;
		cout<<"1. Insert element at beginning"<<endl;
		cout<<"2. Insert element at end"<<endl;
		cout<<"3. Insert element after a position"<<endl;
		cout<<"4. Delete element at beginning"<<endl;
		cout<<"5. Delete element at end"<<endl;
		cout<<"6. Delete a particular element in the list"<<endl;
		cout<<"7. Search for an element"<<endl;
		cout<<"8. Display all the elements of the linked list"<<endl;
		cout<<"9. Check the emptiness of the list"<<endl;
		cout<<"10. Count the number of elements in a linked list"<<endl;
		cout<<"11. Reversing the elements of the linked list"<<endl;
		//cout<<"10. Reverse the elements of the list"<<endl;
		cout<<"99. Exit"<<endl;
		cout<<"Enter your choice->";
		cin>>ch;

		/* The choice is switched for different options */
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the element to be inserted at the beginning"<<endl;
				int val;
				cin>>val;
				sl.insert_begin(val);
				cout<<endl;
			}
				break;
			case 2:
			{
				cout<<"Enter the element to be inserted at the end"<<endl;
				int val;
				cin>>val;
				sl.insert_end(val);
				break;
				cout<<endl;
			}
			case 3:
			{
				cout<<"Enter the element to be inserted after a position"<<endl;
				int val;
				cin>>val;
				cout<<"Enter the position after which the element is to be inserted"<<endl;
				int pos;
				cin>>pos;
				sl.insert_pos(val,pos);
				break;
				cout<<endl;
			}
			case 4:
			{
				int element = sl.delete_first();
				if(element!=-1)
					cout<<"Element successfully deleted from the beginning of the list "<<element<<endl;
				else
					cout<<"Element not deleted from the list"<<endl;
				break;
				cout<<endl;
			}
			case 5:
			{
				int element = sl.delete_last();
				if(element!=-1)
					cout<<"Element successfully deleted from the end of the list "<<element<<endl;
				else
					cout<<"Element not deleted from the list"<<endl;
				break;
				cout<<endl;
			}
			case 7:
			{
				cout<<"Enter the search element"<<endl;
				int search_element;
				cin>>search_element;
				int pos;
				pos = sl.search(search_element);
				if(pos!=-1)
				{
					cout<<"Element found at position "<<pos<<" in the linked list"<<endl;
				}
				else
				{
					cout<<"Element "<<search_element<<" not found in the linked list"<<endl;
				}
				break;
				cout<<endl;
			}
			case 8:
			{
				cout<<"The elements of the linked list are"<<endl;
				sl.display();
				break;
			}
			case 9:
			{
				int empty;
				empty = sl.isEmpty();
				if(empty == 1)
				{
					cout<<"The linked list is empty"<<endl;
				}
				else
				{
					cout<<"The linked list is not empty"<<endl;
				}
				break;
				cout<<endl;
			}
			case 10:
			{
				cout<<"Counting the number of elements"<<endl;
				int count;
				count = sl.count();
				cout<<"Number of nodes in the linked list is "<<count<<endl;
				cout<<endl;
				break;
			}
			case 11:
			{
				sl.display();
				cout<<"Elements of the linked list is reversed."<<endl;
				sl.reverse();
				sl.display();
				cout<<endl;
				break;
			}
			case 6:
			{
				cout<<"Enter the element to be deleted"<<endl;
				int element;
				cin>>element;
				sl.delete_ele(element);
				cout<<endl;
				break;
			}
			case 99:
			{
				cout<<"Exit..."<<endl;
				exit(0);
				break;
				cout<<endl;
			}
			default:
				cout<<"Invalid choice, please try again!"<<endl;
				cout<<endl;

		}
	}
	return 0;
}

/* Functions */

node* single_list::create_node(int val)
{
	struct node* temp;
	temp = new(struct node);
	temp->info = val;
	temp->next = NULL;
	return temp;
}

/* checking if the linked list is empty */
int single_list::isEmpty()
{
	if(start == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/* inserting element at beginning */
void single_list::insert_begin(int val)
{
	struct node* temp;
	temp = create_node(val);
	int empty;
	empty = isEmpty();
	if(empty)
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		temp->next = start;
		start = temp;
	}
	cout<<"Element inserted at the beginning"<<endl;

}


/* inserting element at the end */
void single_list::insert_end(int val)
{
	struct node* temp;
	struct node* p;
	temp = create_node(val);
	int empty;
	empty = isEmpty();
	if(empty)
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		while(p->next!= NULL)
		{
			p = p->next;
		}
		p->next = temp;
		temp->next = NULL;
	}
	cout<<"Element inserted at the end of the linked list"<<endl;
}

/* inserting element after a position */
void single_list::insert_pos(int val,int pos)
{
	int c = 0;
	struct node* temp;
	struct node* p;
	temp = create_node(val);
	if(pos == -1)
	{
		insert_begin(val);
	}
	else
	{
		p = start;
		c = 0;
		int flag = 0;
		while(p != NULL)
		{
			if(c == pos)
			{
				temp->next = p->next;
				p->next = temp;
				cout<<"Element successfully added after position "<<pos<<endl;
				flag = 1;
				break;
			}
			c++;
			p = p->next;
		}
		if(flag == 0)
		{
			cout<<"Invalid position. Please try again!"<<endl;
		}
	}
}

/* Deleting first element */
int single_list::delete_first()
{
	struct node* temp;
	int element;
	int empty;
	empty = isEmpty();
	if(empty)
	{
		cout<<"Linked list is empty"<<endl;
		return -1;
	}
	else if(start->next == NULL)
	{
		//Only one element
		element = start->info;
		start = NULL;
	}
	else
	{
		temp = start;
		start = temp->next;
		element = temp->info;
		return element;
	}
}


/* Deleting last element */
int single_list::delete_last()
{
	struct node* p;
	int element;
	int empty;
	empty = isEmpty();
	if(empty)
	{
		cout<<"Linked list is empty"<<endl;
		return -1;
	}
	else if(start->next == NULL)
	{
		//Only one element in the linked list
		element = start->info;
		start = NULL;
		return element;
	}
	else
	{
		p = start;
		while(p->next->next != NULL)
		{
			p = p->next;
		}
		element = p->next->info;
		p->next = NULL;
		return element;
	}
}


/* searching for an element */
int single_list::search(int val)
{
	struct node* temp;
	int empty;
	int flag = 0;
	int pos = 0;
	empty = isEmpty();
	if(empty)
	{
		cout<<"List is empty"<<endl;
		return -1;
	}
	else
	{
		temp = start;
		while(temp != NULL)
		{
			if(temp->info == val)
			{
				flag = 1;
				break;
			}
			else
			{
				temp = temp->next;
				pos ++;
			}
		}
		if(flag)
		{
			return pos;
		}
		else
		{
			return -1;
		}
	}
}

/* displaying all elements of the linked list */
void single_list::display()
{
	struct node* temp;
	temp = start;
	int empty;
	empty = isEmpty();
	if(!empty)
	{
		while(temp != NULL)
		{
			cout<<temp->info<<" -> ";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
		return;
	}
	else
	{
		cout<<"\n";
	}
}


/* counting the number of nodes in a linked list */
int single_list::count()
{
	struct node* temp;
	temp = start;
	int count = 0;
	int empty;
	empty = isEmpty();
	if(empty)
	{
		return 0;
	}
	while(temp!=NULL)
	{
		temp = temp->next;
		count ++;

	}
	return count;
}

/* reversing the elements of the linked list */
void single_list::reverse()
{
	struct node* prev = NULL;
	struct node* current = start;
	struct node* nex;
	while(current != NULL)
	{
		nex = current->next;
		current->next = prev;
		prev = current;
		current = nex;
	}
	start = prev;
}

/* deleting specific element */
void single_list::delete_ele(int ele)
{
	struct node* temp;
	int empty;
	int flag = 0;
	empty = isEmpty();
	if(empty)
	{
		cout<<"Linked list empty. No element to be deleted"<<endl;
		return ;
	}
	else
	{
		temp = start;
		if(temp->info == ele)
		{
			start = temp->next;
			cout<<"Element "<<ele<<" deleted from the linked list"<<endl;
			return ;
		}
		while(temp->next->next !=NULL)
		{
			if(temp->next->info == ele)
			{
				flag = 1;
				temp->next = temp->next->next;
				break;
			}
			temp = temp->next;
		}
		if(temp->next->info == ele)
		{
			temp->next = NULL;
			cout<<"Element "<<ele<<" deleted from the linked list"<<endl;
			return ;
		}
		if(flag)
		{
			cout<<"Element "<<ele<<" deleted from the linked list"<<endl;
			return ;
		}
		else
		{
			cout<<"Element "<<ele<<" not found in the list"<<endl;
			return ;
		}
	}
	return ;
}

