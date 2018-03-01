#include<stdio.h>
int main()
{
	int a[10][10];
	int m,n,i,j,count;
	printf("enter the order of matix\n");
	scanf("%d%d",&m,&n);
	printf("enter the elements of a matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			{
				++count;
			}
			
		}
	}
	if(count>(m*n)/2)
	{
		printf("the matrix is asparse matrix\n");
	}
	else
	{
	printf("the matrix is not a sparse matrix\n");	
	}
	printf("no of zeros %d",count);
	return 0;
	
}
