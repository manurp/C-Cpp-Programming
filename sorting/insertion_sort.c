#include <stdio.h>

void insertion_sort(int* A, int n) {
    int i, value, hole;
    for(i = 1; i < n; i++) {
        value = A[i];
        hole = i;
        while(hole > 0 && A[hole - 1] > value) {
            A[hole] = A[hole - 1];
            hole--;
        }
        A[hole] = value;
    }
}

int main() {
    int a[] = {0,12,4,5,8,6,7,10,2,1};
    int i;
    insertion_sort(a,10);
    for(i = 0; i<10 ; i++) printf("%d ",a[i]);
    return 0;
}
