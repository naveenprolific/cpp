#include<stdio.h>

int search(int a[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		return i;
	}
	return -1;
}
int main()
{
	int n,x,i;
	int a[n];
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element to search");
	scanf("%d",&x);
	
	printf("%d is at index %d",x,search(a,n,x));
	getchar();
	return 0;
}
 

