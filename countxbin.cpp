#include<bits/stdc++.h>
using namespace std;
int first(int a[],int l,int h,int x,int n){
	if(l<=h){
		int m=(l+h)/2;
		if((m==0||x>a[m-1])&&x==a[m]){
			return m;
		}
		else if(x>a[m]){
			return first(a,m+1,h,x,n);
		}
		else{
			return first(a,l,m-1,x,n);
		}
	}
	return -1;
}
int last(int a[],int l,int h,int x,int n){
	if(l<=h){
		int m=(l+h)/2;
		if((m==n-1||x<a[m+1])&&x==a[m]){
			return m;
		}
		else if(x<a[m]){
			return last(a,l,m-1,x,n);
		}
		else{
			
			return last(a,m+1,h,x,n);
		}
	}
	return -1;
}
int count(int a[],int x,int n){
	int i,j;
	i=first(a,0,n-1,x,n);
	if(i==-1){
		return i;
	}
	j=last(a,i,n-1,x,n);
	return (j-i+1);
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
	cout<<count(a,x,n);
	return 0;
}






