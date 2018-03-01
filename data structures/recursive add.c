#include<stdio.h>
int add(int m,int n)
{ 
 int a;
	if(n==0)
	return m;
	a = add(m,n-1)+1;
	return a;
}
int main()
{
	int x,y ,sum;
	printf("enter 2 integers\n");
	scanf("%d%d",&x,&y);
	sum = add(x,y);
	printf("the sum is %d\n",sum);
	return 0;
}
