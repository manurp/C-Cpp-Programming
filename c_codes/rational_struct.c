#include <stdio.h>


#define TRUE 1
#define FALSE 0

typedef struct rational {
	int numerator;
	int denominator;
}rational;

void reduce(rational* inrat,rational* outrat)
{
	int a, b, rem;

	*outrat = *inrat;

	if(inrat->numerator>inrat->denominator) {
		a = inrat->numerator;
		b = inrat->denominator;
	}
	else {
		a = inrat->denominator;
		b = inrat->numerator;
	}
	while (b!=0) {
		rem = a%b;
		a = b;
		b = rem;
	}
	outrat->numerator /=a;
	outrat->denominator /=a;
}


int equal(rational* rat1,rational* rat2) {
	rational r1, r2;

	reduce(rat1, &r1);
	reduce(rat2, &r2);
	if(r1.numerator==r2.numerator && r1.denominator==r2.denominator)
		return TRUE;
	return FALSE;
}

int main()
{
	rational r1 = {8,2};
	rational r2 = {16,4};

	printf("%d\n",equal(&r1,&r2));

	return 0;
}
