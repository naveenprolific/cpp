#include<bits/stdc++.h>
using namespace std;
int main(){
	long int t,n,d;
	long int j=0,count=0;
	int arr[100];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		count=0;
		j=0;
		while(n>0){
			d = n%10;
			arr[j]=d;
			j++;
		n=n/10;
		}
		count=arr[0]+arr[j-1];
		cout<<count<<endl;
	}
	
	return 0;
}
