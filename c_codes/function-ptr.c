#include <stdio.h>

void sayHello(char* name) {
	printf("Hello %s\n",name);
}

int main() {
	void (*fptr)(char*);
	fptr = sayHello; // or &sayHello
	fptr("Manu");  //or(*fptr)("... ")

	return 0;
}
