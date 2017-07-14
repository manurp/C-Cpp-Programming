#include<stdio.h>
#include<math.h>

int main()
{
	double x;
	double sqrt_x;

	printf("Enter the number: ");
	scanf("%lf",&x);

	sqrt_x=
	sqrt(x);

	printf("The square root of %lf is ",x);
	printf("%lf\n",sqrt_x);

	return 0;
}