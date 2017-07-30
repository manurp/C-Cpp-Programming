#include <stdio.h>
#include <math.h>

int compare(int a, int b) {
    return a-b; //return b-a to sort in descending order
}

int absolute_compare(int a, int b) {
    return abs(a) - abs(b);
}

void BubbleSort(int* A,int size, int (*compare)(int, int)) {
    int i, j, temp;

    for(i = 0;i < size; i++)
        for(j = 0;j < size-1; j++) {
            if(compare(A[j],A[j+1]) > 0) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
}

int main() {
    int i;
    int A[] = {5,3,7,4,9,10};
    BubbleSort(A, 6, compare);
    for(i = 0; i < 6; i++) printf("%d ",A[i]);
    printf("\n");
    int B[] = {-2,4,7,0,-32,50};
    BubbleSort(B, 6, absolute_compare);
    for(i = 0; i<6;i++)
        printf("%d ",B[i] );
    return 0;
}
