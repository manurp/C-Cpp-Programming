#include <iostream>
using namespace std;

int moves; // Global variable default value is zero

void hanoi(int m, char a, char b, char c) {
    moves++;
    if(m==1) {
        cout << "Move disc "<< m << " from " << a << " to " << c << endl;
    }
    else {
        hanoi(m-1, a, c, b);
        cout << "Move disc " << m << " from "<< a << " to " << c << endl;
        hanoi(m-1, b, a, c);
    }
}

int main() {
    int discs;
    cout<<"Enter the number of discs: ";
    cin >> discs;
    cout<<endl;
    hanoi(discs, 'A', 'B', 'C');  // A is source, B is auxillary, C is destination tower
    cout<<"Total moves = "<<moves<<endl;
    return 0;
}
