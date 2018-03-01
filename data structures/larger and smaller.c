#include<stdio.h>

int main()
{
	int a[100],n,i,large,small;
	printf("enter the size of array\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	large = a[0];
	for(i=0;i<n;i++)
	{
	  if (large < a[i])
	  {
	   large = a[i];
	  }	
	}
	printf("larger elemt %d\n",large);
	small = a[0];
	for(i=0;i<n;i++)
	{
		
	if (small > a[i])
	  {
	    small =a[i]	;
	  }	
     }
     printf("smaller elemt %d\n",small);
     return 0;
}
