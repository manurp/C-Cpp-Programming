#include <stdio.h>

int compare(int a, int b) {
	if(a>b) return 1;
	return -1;
}

int compare_rev(int a, int b) {
    if(b>a) return 1;
    else return -1;
}

void BubbleSort(int *A, int n, int (*fptr)(int,int)) {
	int i, j, temp;

	for(i=0;i<n;++i)
		for(j=0;j<n-i;++j) {
			if(fptr(A[j],A[j+1])>0) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
}

int main() {
	int i, A[] = {3,1,5,4,2,6};
	BubbleSort(A,6,compare);
	for(i=0;i<6;++i) printf("%d ", A[i]);
	printf("\n");
	BubbleSort(A,6,compare_rev);
	for(i=0;i<6;++i) printf("%d ", A[i]);

	return 0;
}
