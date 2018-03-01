#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,i;
float sum =0,x, avg;
printf("enter thow many numbers\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	printf("x = ");
	scanf("%f",&x);
	sum += x;
}

 avg = sum /n;
 printf("the average is %f",avg);
 return 0;
}

