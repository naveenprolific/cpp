#include<stdio.h>
int main()
{
	int n,i;
	int a[n];
	printf(" enter the size of array ");
	scanf("%d",&n);
	printf("enter the elements of array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	int temp;
    int j;
	for(i=0;i<n;i++)
	{
		temp = a[i];
		j=i;
		while(j>0 && a[j-1]>temp)
		{
			a[j]=a[j-1];
			--j;
		}
		a[j] = temp;
	
	}
	
	printf("the array elements are :");

	for(i=0;i<n;i++)
	{
	printf("%d\n",a[i]);
		
	}
}
