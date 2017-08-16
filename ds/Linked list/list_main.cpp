//#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List li1;
    li1.push(5);li1.push(3);li1.push(2);
    li1.insertAfter(3,8);
    cout << li1.pop() << endl << li1.pop() << endl<< li1.pop() << endl ;
    cout << li1.pop();
    return 0;
}
