#include<stdio.h>
int main()
{
	int n,i,*p,sum=0 ;
	printf("enter numbr of elements");
	scanf("%d",&n);
	p = (int*)malloc(n*sizeof(int));
	if(p == NULL)
	{
		printf("error!");
		return 0;
	}
	printf("enter the elements of array");
	for(i=0;i<n;++i)
	{
		scanf("%d",p+i);
		sum = sum + *(p+i);
	}
	printf(" elements of array are");
	for(i=0;i<n;i++)
	{
	printf("%d\n",p[i]);
	}
	free(p);
	return 0;
}
