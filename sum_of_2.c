#include<stdio.h>

int main()
{
	int a,b;
	int sum;

	printf("Enter the 2 numbers\n");
	scanf("%d%d",&a,&b);

	sum=a+b;

	printf("The sum %d and %d is: ",a,b);
	printf("%d\n",sum);

	return 0;

}