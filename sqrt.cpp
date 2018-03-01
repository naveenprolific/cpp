#include<bits/stdc++.h>
using namespace std;
int sq(int n){
	if(n==0||n==1){
		return n;
	}
	int s=1,e=n,ans;
	while(s<=e){
		int mid=(s+e)/2;
		if(mid*mid==n){
			return mid;
		}
		if(mid*mid<n){
			s=mid+1;
			ans=mid;
		}
		else{
			e=mid-1;
		}
	}
	return ans;
}
int main(){
	int n;
	cout<<"enter the value of n"<<endl;
	cin>>n;
	cout<<sq(n);
	return 0;
}
