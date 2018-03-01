#include<stdio.h>
int main()
{
	int i,n,sum =0,value;
	printf("enter the number of integers");
	scanf("%d",&n);
	printf("enter %d integers",n);
	for(i=0;i<=n;i++)
	{
		scanf("%d",&value);
		sum =sum + value;
	}
	printf("%d\n",sum);
	while(i<n)
	{ 
	scanf("%d",&value);
		sum = sum + value;
		i++;
	}
	printf("%d\n",sum);
	return 0;
}
