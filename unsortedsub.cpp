#include<bits/stdc++.h>
using namespace std;
void unsortedsub(int a[],int n){
	int s=0,e=n-1,i,max,min;
	for(s=0;s<n-1;s++){
		if(a[s]>a[s+1]){
			break;
		}
	}
	if(s==n-1){
		cout<<"-1";
	}
	for(e=n-1;e>0;e--){
		if(a[e]<a[e-1]){
			break;
		}
	}
	max=a[s],min=a[e];
	for(i=s+1;i<e;i++){
		if(a[i]>max){
			max=a[i];
		}
		if(a[i]<min){
			min=a[i];
		}
	}
	for(i=0;i<s;i++){
		if(a[i]>min){
			s=i;
			break;
		}
	}
	for(i=n-1;i>=e+1;i--){
		if(a[i]<max){
			e=i;
			break;
		}
	}
	cout<<s<<"..."<<e;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	unsortedsub(a,n);
	return 0;
}






