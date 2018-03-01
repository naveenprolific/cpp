#include<bits/stdc++.h>
using namespace std;
int bin(int a[],int k,int l,int h);
bool maj(int arr[],int k,int n){
	int i=bin(arr,k,0,n-1);
	if(i == -1){
		return false;
	}
	if(((i+n/2) <= (n-1)) && arr[i+n/2]==k){
		return true;
	}
	else{
		return false;
	}
}

int bin(int a[],int k,int l,int h){
	
	if(l<=h){
		int m=(l+h)/2;
		if((m == 0 || k > a[m-1]) && (a[m] == k)){
			return m;
		}
		else if(a[m]>k){
			return bin(a,k,l,m-1);
		}
		else{
			return bin(a,k,m+1,h);
		}
	}
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
	if(maj(a,x,n)){
	cout<<"yea....";
	}
	else{
		cout<<"offoo/...";
	}
	return 0;
}
