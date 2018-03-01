#include<bits/stdc++.h>
using namespace std;
int samecount(int a[],int l,int h){
	if(l>h){
		return -1;
	}
		int m=(l+h)/2;
		int mid=a[m];
		if(m==a[m]){
			return m;
		}
		int li=max(m+1,mid);
		int left = samecount(a,li,h);
		if(left>0){
			return left;
		}
		int ri = min(m-1,mid);
		int right= samecount(a,l,ri);
		return right;
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
