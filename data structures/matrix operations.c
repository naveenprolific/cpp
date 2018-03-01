#include<stdio.h>
int main()
{
	int m,n,i,j,a[20][20],b[20][20],c[20][20];
	printf("enter no rows and columns\n");
	scanf("%d%d",&m,&n);
	printf("enter the elements of first matrix\n");	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		scanf("%d",&a[i][j]);	
		}
	}
	printf("enter the elements of first matrix\n");
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		scanf("%d",&b[i][j]);	
		}
	}
	
	
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("the sum of matrices\n");
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
			printf("\n");
		}
	}
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		c[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("the difference of matrices\n");
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
			printf("\n");
		}
	}
	return 0;
}
