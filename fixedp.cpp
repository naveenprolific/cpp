#include<bits/stdc++.h>
using namespace std;
int samecount(int a[],int l,int h){
	if(l<=h){
		int m=(l+h)/2;
		if(m==a[m]){
			return m;
		}
		if(m>a[m]){
			return samecount(a,m+1,h);
		}
		else{
			return samecount(a,l,m-1);
		}
	}
	return -1;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<samecount(a,0,n-1);
	return 0;
}
