#include<bits/stdc++.h>
using namespace std;
int fib(int n){
	if(n<=1){
		return n;
	}
	else{
		return fib(n-1)+fib(n-2);
	}
}
int main(){
	int n;
	cout<<"enter the value of n"<<endl;
	cin>>n;
	int res=fib(n);
	cout<<"nth fib num is :"<<res<<endl;
	return 0;
}
