#include<stdio.h>
int main()
{
	int m,n,p,q,i,j,k,sum = 0;
	int a[10][10],b[10][10],c[10][10];
	printf("enter the rows and columns of first matrix\n");
	scanf("%d%d",&m,&n);
	printf("enter the elements of matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the rows and columns of second matrix\n");
	scanf("%d%d",&p,&q);
	if(n!=p)
	{
		printf("matrix multiplication is not possible\n");

	}
	else
	{
	
     	printf("enter the elements of matrix\n");
	    for(i=0;i<m;i++)
     	{
		  for(j=0;j<n;j++)
		  {
			scanf("%d",&a[i][j]);
	     	}
	    }
    

	for(i=0;i<m;i++)
     	{
		  for(j=0;j<q;j++)
		  {
		  	for(k=0;k<p;k++)
		  	{
		  		
		  	sum = sum + a[i][k]*b[k][j];	
			}
			c[i][j] = sum ;
			sum = 0;
	     	}
	    }
	    printf("after mult\n");
	    for(i=0;i<m;i++)
     	{
		  for(j=0;j<q;j++)
		  {
			printf("%d\t",c[i][j]);
			printf("\n");
	     	}
	    }
	}
	
	    return 0;
}
