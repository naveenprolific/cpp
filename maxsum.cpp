#include<bits/stdc++.h>
using namespace std;
void mincoins(int a[],int n){
	int maxs=0,maxe=0;
	for(int i=0;i<n;i++){
		maxe+=a[i];
		if(maxe<0){
			maxe=0;
		}
		if(maxs<maxe){
			maxs=maxe;
		}
	}
	cout<<"sum is :"<<maxs;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	mincoins(a,n);
	return 0;
}
