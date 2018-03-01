#include<stdio.h>
int main()
{
	int first,second,*p,*q,sum;
	printf("enter two integers");
	scanf("%d%d",&first,&second);
	p=&first;
	q=&second;
	sum = *p + *q;
	printf("the sum 2 integers is %d",sum);
	
	
	return 0;
	
	
}
