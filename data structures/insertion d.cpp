#include<iostream>
#define maxsize 10
using namespace std;

class insert
{
	public : 
	   int i,j,key,n;
	   int a[maxsize];
	   
	    void Dinsert()
	    {
	    	printf("enter the number of items to insert\n");
	    	scanf("%d",&n);
	    	printf("enter the values  to insert\n");
	    	for(i=0;i<n;i++)
	    	{
	    		scanf("%d",&a[i]);
			}
	    	for(i=0;i<=n;i++)
	    	{
	    		key = a[i];
	    		j = i;
	    		while(j>0 && a[j-1]<a[i])
	    		{
	    			a[j]=a[j-1];
	    			--j;
				}
				a[j]= key;
			}
			
			printf("the soretd elements are:\n");
	    		for(i=0;i<n;i++)
	    	{
	    		printf("%d\n",a[i]);
			}
		}
};

 int main()
 {
 	insert d;
 	d.Dinsert();
 	
 	return 0;
 	
 }
