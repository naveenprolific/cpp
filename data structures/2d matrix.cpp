#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j;
	int a[m][n];
	cout<<"enter the no of rows and columns"<<endl;
	cin>>m>>n;
	cout<<"enter the elements of matrix"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
	   {
		cin>>a[i][j];
	   }  
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
	   {
		cout<<a[i][j]<<endl;
	   }  
	}
	
	return 0;
}
