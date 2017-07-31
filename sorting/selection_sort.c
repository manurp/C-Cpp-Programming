#include <stdio.h>

void selection_sort(int* A, int n) {
    int i, j, iMin;
    for(i = 0; i< n; i++) {
        iMin = i;
        for(j = i+1; j < n; j++) {
            if(A[j] < A[iMin])
                iMin = j;
        }
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}

int main() {
    int a[] = {1,12,4,5,8,6,7,10,0,2};
    int i;
    selection_sort(a,10);
    for(i = 0; i<10 ; i++) printf("%d ",a[i]);
    return 0;
}
