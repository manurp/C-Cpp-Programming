#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a,const void* b) {
	int A = *((int*)a);
	int B = *((int*)b);
	return A-B; // check B- A / abs(A)-abs(B);
}

int main() {
	int i,A[] = {-31,1,5,-4,3,2};
	qsort(A,6,sizeof(int),compare);
	for(i=0;i<6;i++) printf("%d ", A[i]);
}
