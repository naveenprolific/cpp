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
void reverse(char *c,int n)
{
	int i;
	for(i=0;i<=n;i++)
 	{
 		push(c[i]);
	 }
	 for(i=0;i<=n;i++)
 	{
 	   c[i]	= pop();
 		
	 }
	 
	
}
 

int main()
 {
 	
 	char c[100];
 	printf("enter  a string\n");
 	gets(c);
 	int n = strlen(c);
 	  reverse(c,strlen(c));
 	

 
 	
 	
 }
