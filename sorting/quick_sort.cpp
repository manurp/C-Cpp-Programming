#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int* A, int start, int end) {
    int pivot  = A[end];
    int pIndex = start;
    for(int i = start; i < end; i++) {
        if( A[i] <= pivot) {
            swap(A[i],A[pIndex]);
            pIndex++;
        }
    }
    swap(A[pIndex], A[end]);
    return pIndex;
}

int randomizedPartition(int* A, int start, int end) {  //To avoid worst case when the array is already sorted
    srand(time(NULL));
    int pivotIndex = rand()%(end-start+1) + start; //Random number in the range [start,end]
    //cout << pivotIndex <<" " <<start <<" " <<end <<" " <<endl;
    swap(A[pivotIndex], A[end]);
    return partition(A, start, end);
}

void quick_sort(int* A, int start, int end) {
    if(start < end) {
        int pIndex = randomizedPartition(A, start, end);
        quick_sort(A, start, pIndex-1);
        quick_sort(A, pIndex+1, end);
    }
}

int main() {
    int a[] = {7,4,2,5,6,9,1,0};
    quick_sort(a, 0, 7);
    for(int i = 0; i < 8; i++)
        cout<< a[i] <<" ";
    return 0;
}
