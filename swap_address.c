#include<stdio.h>

void swap(int*,int*);

void main()
{
	int a=10,b=15;
	printf("a=%d, b=%d to swap\n",a,b);
	swap(&a,&b);
	printf("a=%d, b=%d after swap\n",a,b);
}

void swap(int *pa,int *pb){
	int t=*pa;
	*pa=*pb;
	*pb=t;
}