#include<bits/stdc++.h>
using namespace std;
int main(){
	long int t,n,d;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		long int count=0;
		while(n!=0){
			d = n%10;
	    if(d==4){
			count++;
		}
		n=n/10;
		}
		cout<<count<<endl;
		count=0;
	}
	
	return 0;
}
