#include<bits/stdc++.h>
using namespace std;
int bin(int a[],int k,int l,int h);
int binp(int a[],int l,int h){
	if(h<l){
		return -1;
	}
	if(l==h){
		return l;
	}
		int m=(l+h)/2;
		if(m>l&&a[m]<a[m-1]){
			return m-1;
		}
		if(h>m&&a[m]>a[m+1]){
			return m;
		}
	    if(a[l]>=a[m]){
	    	return binp(a,l,m-1);
		}
			return binp(a,m+1,h);
	/*
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
	}*/

}
int binpt(int a[],int k,int l, int h){
	if(l>h){
		return -1;
	}
	int p=binp(a,l,h);
	if(p==-1){
		bin(a,k,l,h);
	}
	if(a[p]==k){
		return p;
	}
	if(a[l]<=k){
		return bin(a,k,l,p-1);
	}
	return bin(a,k,p+1,h);
}
int bin(int a[],int k,int l,int h){
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
