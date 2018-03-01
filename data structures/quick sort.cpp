#include<iostream>
#include<cstdlib>
using namespace std;

class quick{
	public:
		int n,i,j;
		int a[100];
		
		int input(){
			cout<<"enter the size of array :"<<endl;
			cin>>n;
			cout<<"enter the array elements :"<<endl;
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			Quick_Sort(a,0,n-1);
			cout<<"The sorted elements are :"<<endl;
			for(i=0;i<n;i++)
			{
				cout<<a[i]<<endl;
			}
			return 0;
		}				
		void swap(int *a,int *b)
		{
			int t;
			t = *a;
			*a = *b; 
			*b = t;
			
		}
		void Quick_Sort(int a[],int p,int r)
		{
			int q;
			if(p<r)
			{
				q = Random_partition(a,p,r);
				Quick_Sort(a,p,q-1);
			    Quick_Sort(a,q+1,r);
			}
			
			
		}
		int Random_partition(int a[],int p,int r)
		{
		int i = p+rand()%(r-p+1);
		
			swap(&a[r],&a[i]);
			return Partition(a,p,r);
		}
			
			
		
		int Partition(int a[],int p,int r)
		{
			int pivot = a[r];
			 i = p -1;
			for(j = p;j<=r-1;j++)
			{
				if(a[j]<= pivot)
				{
					i++;
					swap(&a[i],&a[j]);
				}
				
			}
			swap(&a[i+1],&a[r]);
			return (i+1);
		}
		
		
};
int main()
{
	quick s;
	s.input();
 return 0;
}
