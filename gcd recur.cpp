#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}
int findgcd(int arr[],int n){
	int res=arr[0];
	for(int i=1;i<n;i++){
		res=gcd(arr[i],res);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<findgcd(arr,n);
	return 0;
}
