#include <iostream>
using namespace std;

struct node
{
    int info;
    node* next;
}*last;

class circular_list
{
public:
    circular_list() {
        last = NULL;
    }
    void create_node(int);
    void add_begin(int);
    void display();
    void search();
    void delete_element(int value);
    ~circular_list() {
        if(last==0) {
            return;
        }
        node* s = last;
        node* temp = s->next;
        s = s->next;
        delete temp;
        while(s!=last) {
            temp = s;
            s = s->next;
            delete temp;
        }
        delete last;
    }

};

void circular_list::create_node(int value) {
    node* temp;
    temp = new node;
    temp->info = value;
    if(last==0) {
        last = temp;
        temp->next = last;
    }
    else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void circular_list::add_begin(int value) {
    if(last==0) {
        cout << "First create the list\n";
        return;
    }
    node* temp = new node;
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}

void circular_list::display() {
    if(last==0) {
        cout << "The circular list is empty\n";
        return;
    }
    node* temp = last->next;
    cout << temp->info << " ";
    temp = temp->next;
    while(temp != last->next) {
        cout << temp->info <<" ";
        temp = temp->next;
    }
    cout << endl;
}

void circular_list::search() {
    int val;
    cout << "Enter the value to be searched: ";
    cin >> val;
    cout << endl;
    if(last==0) {
        cout << "Can't search from an empty list\n";
        return;
    }
    int counter = 0;
    node* temp = last->next;
    if(temp->info == val) {
        cout << "The value "<<val<<" found at position "<<counter<<endl;
        return;
    }
    temp = temp->next;
    counter++;
    while(temp != last->next) {
        if(temp->info == val) {
            cout << "The value "<<val<<" found at position "<<counter<<endl;
            return;
        }
        temp = temp->next;
        counter++;
    }
    cout <<"Not found\n";
}

void circular_list::delete_element(int value) {
    node *temp, *s;
    s = last->next;
    if(last==0) {
        cout << "Can't delete from an empty list\n";
        return;
    }

    //If the list has only one element
    if(last->next==last && last->info==value) {
        temp=last;
        last=0;
        delete temp;
        cout << "Element deleted " <<value <<endl;
        return;
    }
    // First element deletion
    if(s->info == value) {
        temp = s;
        last->next = s->next;
        delete temp;
        cout << "Element deleted " <<value <<endl;
        return;
    }

    // Deletion of element in between
    while(s->next != last) {
        if(s->next->info==value) {
            temp = s->next;
            s->next = temp->next;
            delete temp;
            cout << "Element deleted " <<value <<endl;
            return;
        }
        s = s->next;
    }

    // Deletion of last element
    if(s->next->info == value) {
        temp = s->next;
        s->next = last->next;
        delete temp;
        last = s;
        cout << "Element deleted " <<value <<endl;
        return;
    }

    cout << "Element not found\n";
}

int main() {
    circular_list cl1;
    cl1.create_node(5);
   // cl1.add_begin(12);
    //cl1.add_begin(16);
    //cl1.display();
    //cl1.search();
    while(1) {
        int choice;
        cout << "1. Add begin\n";
        cout << "2. Search\n";
        cout << "3. Delete Element\n";
        cout << "4. Display\n";
        cout << "5. Quit\n";
        cin >> choice;
        int val;
        if(choice==5)
            break;
        switch(choice) {
            case 1:
                cout << "Enter the value to be added: ";
                cin >> val;
                cl1.add_begin(val);
                break;

            case 2:
                cl1.search();
                break;

            case 3:
                cout << "Enter the value to be deleted: ";
                cin >> val;
                cl1.delete_element(val);
                break;

            case 4:
                cl1.display();
                break;

            default:
                cout<< "Invalid choice\n";
        }
    }
   // cl1.display();
    return 0;
}
