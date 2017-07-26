#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXCOLS 80 //Maximum columns in the input line
#define TRUE 1
#define FALSE 0

struct stack
{
	int top;
	double items[MAXCOLS];
};

double eval(char []);
double pop(struct stack*);
void push(struct stack*, double);
int empty(struct stack*);
int isdigit(char); //predefined macro
double oper(int, double, double);

void main() {
	char expr[MAXCOLS];
	int position = 0;

	while((expr[position++] = getchar()) != '\n');

	expr[--position] = '\0';
	printf("The original postfix expression is %s",expr);

	printf("\n%f", eval(expr));
}


double eval(char expr[]) {
	int c, position;
	double opnd1, opnd2, value;
	struct stack opndstk;

	opndstk.top = -1;

	for(position = 0; (c = expr[position]) !='\0'; position++)
		if(isdigit(c))
			push(&opndstk,(double)(c-'0'));
		else {
			opnd2 = pop(&opndstk);
			opnd1 = pop(&opndstk);
			value = oper(c, opnd1, opnd2);
			push(&opndstk, value);
		}

	return (pop(&opndstk));
}

int isdigit(char symb) {
	return (symb>='0' && symb<='9');
}

double oper(int symb, double op1, double op2) {
	switch(symb) {
		case '+':return(op1+op2);
		case '-':return(op1-op2);
		case '*':return(op1*op2);
		case '/':return(op1/op2);
		case '$':return (pow(op1,op2));
		default:printf("%s\n","Illegal operation!!");
		exit(1);
	}
}

int empty(struct stack* ps) {
	if(ps->top == -1)
		return(TRUE);
	else
		return(FALSE);
}

double pop(struct stack* ps) {
	if(empty(ps)) {
		printf("Stack underflow!!!\n");
		exit(1);
	}
	return(ps->items[ps->top--]);
}

void push(struct stack* ps, double x) {
	if(ps->top == MAXCOLS-1) {
		printf("Stack overflow\n");
		exit(1);
	}
	else
		ps->items[++(ps->top)] = x;
	return;
}
