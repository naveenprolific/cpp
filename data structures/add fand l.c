#include<stdio.h>

int main()

{
	int n , first, last,sum ;
    printf("enter the integer\n");
	scanf("%d",&n);
	last = n%10;
	first = n;
	while(first>=10)
	{
	   first= first/10;
	}
	sum = first + last;
	printf("the summ is %d",sum);
	return 0;
		
	
}
