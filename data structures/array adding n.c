#include<stdio.h>
int main()
{ 
int n,i,sum = 0;
int a[100];
printf("enter the no of int to add\n");
scanf("%d",&n);
printf("enter the elements of array\n");

for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum =sum + a[i];
	}
	printf("%d\n",sum);
	
return 0;	
}
