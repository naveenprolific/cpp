#include<stdio.h>
int main()
{
	int a[100],n,i,position,value;
	printf("enter the size of array\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the position to insert\n");
	scanf("%d",&position);
    printf("enter the value to be inserted\n");
    scanf("%d",&value);
    for(i =n-1;i >= position - 1;i--)
    {
	a[i+1]= a[i];
    }
    a[position - 1] = value;
    printf("array after insertion\n");
    for(i=0;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
