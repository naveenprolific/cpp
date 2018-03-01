#include<stdio.h>
int add(int);
int main()
{ 
int n,result;

printf("enter the integer");
scanf("%d",&n);
result = add(n);
printf("%d\n",result);
return 0;

}
int add(int n)
{
	int sum = 0;
	if(n ==0)
	{
		return 0;
	}
	sum = n%10 + add(n/10);
	return sum;
}
