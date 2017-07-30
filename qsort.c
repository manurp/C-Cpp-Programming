#include<stdio.h>
#include<stdlib.h>

int comp(const void* a,const void* b){
	return(*(int*)a < *(int*)b); //Change the sign(>) to sort in ascending order
}

int main()
{
	int data[]={1,2,3,4,5};
    int i;
	qsort(data,5,sizeof(int),comp);

	for(i=0;i<5;i++){
		printf("%d ",data[i]);
	}
	return 0;
}
