#include<stdio.h>
#include<string.h>

int main()
{
	char str1[]={'H','e','l','l','o',' ','\0'};		//"Hello ";
	char str2[]="World";

	char str[20];

	strcpy(str,str1);
	strcat(str,str2);

	printf("The resulting string is %s\n",str);

	return 0;
}