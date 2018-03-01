#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n,i,j,a[100];
 printf("enter the size of array\n");
 scanf("%d",&n);
printf("enter array elements\n");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
for(j=i+1;j<n;++j){

if(a[i]>a[j])
{
	a[i] = a[i]+a[j];
	a[j]=a[i]-a[j];
	a[i]=a[i]-a[j];
}
}
}
printf("ascend of array\n");
for(i=0;i<n;i++)
{
	printf("%d\n",a[i]);
}
return 0;
} 


