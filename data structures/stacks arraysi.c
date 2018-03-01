#include<stdio.h>
#define MAX_SIZE 101
int a[MAX_SIZE];
int top = 1;
void push(int x)
{ 
if(top == MAX_SIZE-1){
	printf("stack overflown\n");
	return;
}
++top;
a[top] = x;
}
void pop()
{
	if(top==-1){
		printf("no elements to pop");
		return;
	}
	top--;
}
int Top(){
	return a[top];
}
void print()
{
	int i;
	for(i=0;i<=top;i++){
		printf("%d",a[i]);
		
	}
	printf("\n");
}
int main()
{
	push(3);
	print();
	push(6);
    print();
	push(7);
    print();
	pop();
	print();
	push(15);
	print();
	Top();
	print();
	
}
