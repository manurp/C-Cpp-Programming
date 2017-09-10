#include <stdio.h>

/*
Automatic Storage Class
A variable defined within a function or block with auto specifier belongs to automatic storage class. All variables defined within a function or block by default belong to automatic storage class if no storage class is mentioned. Variables having automatic storage class are local to the block which they are defined in, and get destroyed on exit from the block.
Memory Allocated in Ram
Default Value is Garbage Value
*/


int main() {
    auto int a;
    printf("%d\n", a);
    a = 1;
    printf("%d\n", a);
    {
        auto int a= 3;
        printf("%d\n", a);
    }
    return 0;
}
