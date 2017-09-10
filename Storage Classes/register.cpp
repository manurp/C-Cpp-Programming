#include <iostream>
using namespace std;


/*
Register Storage Class
The register specifier declares a variable of register storage class. Variables belonging to register storage class are local to the block which they are defined in, and get destroyed on exit from the block. A register declaration is equivalent to an auto declaration, but hints that the declared variable will be accessed frequently; therefore they are placed in
CPU registers
, not in memory. Only a few variables are actually placed into registers, and only certain types are eligible; the restrictions are implementation-dependent. However, if a variable is declared register, the unary & (address of) operator may not be applied to it, explicitly or implicitly. Register variables are also given no initial value by the compiler.
*/

int main() {
    register int i, sum = 0, n;
    cout << "Enter the value of n: ";
    cin >> n;

    for(i = 1; i <= n; i++)
        sum += i;
    cout << "Sum = " << sum << endl;
    return 0;
}
