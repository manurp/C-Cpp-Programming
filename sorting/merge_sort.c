#include <stdio.h>
#include <stdlib.h>

void merge(int* left, int lsize, int* right, int rsize, int* A, int size) {
    int i = 0, j = 0, k = 0;
    while(i < lsize && j < rsize) {
        if( left[i] <= right[j]) {
            A[k] = left[i];
             i++;
        }
        else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < lsize) {
        A[k] = left[i];
        i++;k++;
    }

    while( j < rsize) {
        A[k] = right[j];
        j++;k++;
    }
}

void merge_sort(int* A, int size ) {
    if(size < 2)
        return;
    int mid;
    if (size%2 == 0) {
        mid = size/2;
    }
    else
        mid = size/2 + 1;
    int* left = (int*)malloc(mid*sizeof(int));
    int* right = (int*)malloc((size-mid)*sizeof(int));
    int i;
    for( i = 0; i < mid; i++)
        left[i] = A[i];
    for(i = mid; i < size; i++)
        right[i-mid] = A[i];
    merge_sort(left,mid);
    merge_sort(right,size-mid);
    merge(left,mid,right,size-mid,A,size);
    free (left);
    free (right);
}

int main() {
    int a[] = {0,12,4,5,8,6,7,10,2,1};
    int i;
    merge_sort(a,10);
    for(i = 0; i<10 ; i++) printf("%d ",a[i]);
    return 0;
}
