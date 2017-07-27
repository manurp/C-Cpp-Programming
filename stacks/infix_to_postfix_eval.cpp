#include "stackt.h"
#include <cmath>
#include <cstdlib>

#define TRUE 1
#define FALSE 0

void postfix(char* infix, char* postr);
int prcd(char op1, char op2);
int isoperand(char op);
int isoperator(char op);

long double eval(char* postr) ;
long double oper(int symb, long double op1, long double op2);

int prcd(char first, char second)  {

    if (first == ')') {
        cout << "Error!!\n";
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
            cout << "Invalid operator\n";
    }

}

int isoperator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '$' )
        return TRUE;
    return FALSE;
}

int isoperand(char test) {
    return isalnum(test);
}

void postfix(char* infix, char* postr) {
    int position, und;
    int outpos =  0;
    char topsymb = '+';
    char symb;
    Stack<char> opstk;

    for (position = 0; (symb = infix[position]) != '\0'; position++) {
        if (isoperand(symb))
            postr[outpos++] = symb;
        else {
            topsymb = opstk.pop(und);
            while (!und  &&  prcd(topsymb, symb)) {
                postr[outpos++] = topsymb;
                topsymb = opstk.pop(und);
            }
            if(!und)
                opstk.push(topsymb);
            if(und||(symb != ')' ))
                opstk.push(symb);
            else
                topsymb = opstk.pop();
        }
    }

    while(!opstk.empty())
        postr[outpos++] = opstk.pop();
    postr[outpos] = '\0';
}

long double oper(int symb, long double op1,long double op2) {
    switch(symb) {
        case '+':return(op1+op2);
        case '-':return(op1-op2);
        case '*':return(op1*op2);
        case '/':return(op1/op2);
        case '$':return (pow(op1,op2));
        default:cout << "Illegal operator!!" <<endl;
    }
}

long double eval(char* postr) {
    int c, position;
    long double opnd1, opnd2, value;
    Stack<long double> opndstk;

    for (position=0; (c=postr[position]) != '\0';position++) {
        if (isdigit(c)) {
             long double temp = static_cast<long double>(c-'0');
            //opndstk.push(static_cast<long double>(c-'0'));  Gives error!!!
            opndstk.push(temp);
        }
        else {
            opnd2 = opndstk.pop();
            opnd1 = opndstk.pop();
            value  = oper(c, opnd1, opnd2);
            opndstk.push(value);
        }
    }
    return opndstk.pop();
}

int main(void) {
    char in[250], post[250];
    long double res;

    cin >> in;
    cout << in <<endl;
    postfix(in,post);
    cout << post <<endl;

    res = eval(post);
    cout << res <<endl;

    return 0;
}
