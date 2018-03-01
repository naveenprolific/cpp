#include<stdio.h>
#include<string.h>
#define max 100
char c[max];
int top = -1;

void push(char x)
{

	if(top == max-1)
	{printf("stack overflow");}
	else{
	top=top+1;
	c[top]= x;

	}
}
int pop(){
	if(top<0)
	{printf("stack underflown \n");}
	else{
	printf("%c",c[top--]);
		}
	}
int main()
{
	
}
