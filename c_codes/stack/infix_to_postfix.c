#include <stdio.h>
#include <stdlib.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

struct stack
{
	int top;
	char items[MAXCOLS];
};

void postfix(char*, char*);
int isoperand(char);
void popandtest(struct stack*, char*, int*);
int prcd(char,char);
void push(struct stack*, char);
char pop(struct stack*);

void main() {
	char infix[MAXCOLS]; //Test case ex: ((a-(b+c))*d)$(e+f)
	char postr[MAXCOLS];
	int pos = 0;

	while((infix[pos++] = getchar()) != '\n');
	infix[--pos] = '\0';
	printf("The original infix expression is %s\n",infix);

	postfix(infix, postr);

	printf("%s\n", postr);
}

int empty(struct stack* ps) {
	if(ps->top == -1)
		return(TRUE);
	else
		return(FALSE);
}

char pop(struct stack* ps) {
	if(empty(ps)) {
		printf("Stack underflow!!!\n");
		exit(1);
	}
	return(ps->items[ps->top--]);
}

void popandtest(struct stack* ps, char* px, int* pund) {
	if(empty(ps)) {
		*pund = TRUE;
		return;
	}
	*pund = FALSE;
	*px = ps->items[ps->top--];
	return;
}

void push(struct stack* ps, char x) {
	if(ps->top == MAXCOLS-1) {
		printf("Stack overflow\n");
		exit(1);
	}
	else
		ps->items[++(ps->top)] = x;
	return;
}

void postfix(char infix[], char postr[]) {
	int position, und;
	int outpos = 0;
	char topsymb = '+';
	char symb;
	struct stack opstk;
	opstk.top = -1;

	for (position = 0; (symb = infix[position]) !='\0'; position++) {
		if(isoperand(symb))
			postr[outpos++] = symb;
		else {
			popandtest(&opstk, &topsymb, &und);
			while(!und && prcd(topsymb,symb)) {
				postr[outpos++] = topsymb;
				popandtest(&opstk, &topsymb, &und);
			}
			if(!und)
				push(&opstk, topsymb);
			if(und || (symb != ')'))
				push(&opstk, symb);
			else
				topsymb = pop(&opstk);
		}
	}

	while(!empty(&opstk))
		postr[outpos++] = pop(&opstk);
	postr[outpos] = '\0';
	return;
}

int prcd(char first, char second) {
	if (first == ')') {
		printf("ERROR!! %c %c \n",first,second);
		exit(1);
		// return FALSE;
	}
	else {
		if(first == '(' || second == '(')
			return FALSE;
		if(first==second)
			return TRUE;
		/*if(second == '(')
			return FALSE*/
		if(second == ')')
			return TRUE;
		if(first == '$' ||(first == '*' && second == '/') ||(first == '/' && second == '*') || (first == '+' && second == '-') || (first == '-' && second == '+'))
			return TRUE;
		if(first == '+' || first == '-')
			return FALSE;
		else
			printf("Invalid operator %c %c\n",first,second);
	}
}

int isoperand(char test) {
	return isalnum(test);
}
