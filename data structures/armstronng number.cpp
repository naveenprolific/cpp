#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,a ,sum =0,t;
	printf("enter the number\n");
	scanf("%d",&n);
	t = n;
	while(n>0)
	{
		a = n%10;
		sum = sum + a*a*a;
		n = n /10;
	}
	if(sum == t)
	{
	  printf("its an armstrong number\n");
	  	
	}
	else
	{
		printf("its  not an armstrong number\n");
	}
	return 0;
	
	
}

