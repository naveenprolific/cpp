#include<bits/stdc++.h>
using namespace std;
int bin(int a[],int k,int l,int h){
	/*
	if(l<=h){
		int m=(l+h)/2;
		if(a[m]==k){
			return m;
		}
		if(a[m]>k){
			return bin(a,k,l,m-1);
		}
		else{
			return bin(a,k,m+1,h);
		}
	}
	*/
	while(l<=h){
		int m=(l+h)/2;
		if(a[m]==k){
			return m;
		}
		if(a[m]>k){
			 h=m-1;
		}
		else{
			l=m+1;
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
	int x;
	cin>>x;
	cout<<bin(a,x,0,n-1);
	return 0;
}
