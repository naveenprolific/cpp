#include<stdio.h>
int main()
{ 
int n,sum = 0,remainder;

printf("enter an integer\n");
scanf("%d",&n);
while(n!=0)
	{
		remainder = n % 10;
		sum =sum + remainder;
		n = n /10;
	}
	printf(" sum of digits in integer is %d\n",sum);
	return 0;
}
	
