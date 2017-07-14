#include<stdio.h>
#include<stdlib.h>

int compt(const void* a,const void* b){
	return(*(int*)a>*(int*)b);
}

int comph(const void *a,const void* b){
	if(*(int*)a<*(int*)b) return -1;
	if(*(int*)a==*(int*)b) return 0;
	if(*(int*)a>*(int*)b) return 1;
}

int main()
{
	int i,key,n;
	printf("Enter the number of elements: ");
	scanf("%d\n",&n);
	int arr[n];

	printf("Enter %d elements\n",n);
	for(i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}

	qsort(arr,n,sizeof(int),compt);

	printf("The sorted array is\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

	printf("Enter the element to be searched in the array\n");
	scanf("%d",&key);

	if(bsearch(&key,arr,n,sizeof(int),comph))
		printf("found!!\n");
	else
		printf("not found.\n");

	return 0;
}