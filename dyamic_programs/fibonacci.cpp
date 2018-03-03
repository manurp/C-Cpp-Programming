#include<iostream>

#define SIZE 30 // Size of fibonacci table

using namespace std;

// Table to save the computed fibonacci values
int table[SIZE];

// First call this in the main function
void init() {
    // Initialize table values to -1 which indicates the value is not computed
    for(int i=0; i<SIZE;i++)
        table[i] = -1;
}

// Function that calculates the nth fibonacci value and returns the same
// Constraint n>=0
int fib(int n) {
    if(table[n] == -1) {
        if(n<=1) {
            table[n] = n;
        }
        else{
            table[n] = fib(n-1)+fib(n-2);
        }
    }
    return table[n];
}

void print_fib_upto_n(int n) {
    cout << "The fibonacci series \n";

    for(int i=0; i<=n;i++)
        cout<<fib(i)<<", ";
    cout << endl;
}

int main() {
    init();

    int n = 15; // To calculate the 6th fibonacci number should be less than SIZE and it starts from 0

    int fib_n = fib(n);

    print_fib_upto_n(n);

    cout << "The " << n << "th fibonacci number is " << fib_n << endl;

    return 0;
}
