#include <stdio.h>

void bubble_sort(int* A, int n) {
    int i, j;

    for(i = 1;i< n; i++) {
        int flag = 0;
        for(j = 0;j < n-i; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break; //The array is already sorted
    }
}

int main() {
    int a[] = {1,2,4,5,8,6,7,8,0,2};
    int i;
    bubble_sort(a,10);
    for(i = 0; i<10 ; i++) printf("%d ",a[i]);
    return 0;
}
