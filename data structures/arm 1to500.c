#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,a ,sum =0,t,q;
	printf("armstrong numbers between 1 to 500\n");
	for(t =1;t<=500;t++)
	{
	n = t ;
	sum =0;
    while(n>0)
	{
		a = n%10;
		sum = sum + a*a*a ;
		n = n /10;
	}
	if(sum == t)
	{
	 printf("%d\n",sum);
	  	
	}
    }
    



}

