#include<bits/stdc++.h>
using namespace std;
#define max 1000
int f[max]={0};
int fib(int n){
	if(n==0){
		return 0;
	}
	if(n==1||n==2){
		f[n]=1;
		return f[n];
	}
	if(f[n]){
		return f[n];
	}
	int k=(n&1)?(n+1)/2:(n/2);
	f[n]=(n&1)?fib(k)*fib(k)+fib(k-1)*fib(k-1):(2*fib(k-1)+fib(k))*fib(k);
	return f[n];
}
int main(){
	int y;
	cin>>y;
	cout<<fib(y)<<endl;
	return 0;
}
