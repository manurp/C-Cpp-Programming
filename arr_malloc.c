#include<stdio.h>
#include<stdlib.h>
//#define MAX 100

int main()
{
	int count,sum=0,i;

	printf("Enter the no. of elements: ");
	scanf("%d",&count);

	int *arr=(int*)malloc(sizeof(int)*count);

	for(i=0;i<count;i++){
		arr[i]=i;
		sum+=i;
	}

	printf("Array sum is : %d\n",sum);

	return 0;


}