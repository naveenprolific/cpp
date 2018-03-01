#include<bits/stdc++.h>
using namespace std;
void mindiff(int arr[],int n){
	if(n<=1){
		return;
	}
	sort(arr, arr+n);
	int diff= arr[1]-arr[0];
	for(int i=2;i<n;i++){
		diff=min(diff,arr[i]-arr[i-1]);
	}
	for(int i=1;i<n;i++){
		if((arr[i]-arr[i-1])==diff){
			cout<<"("<<arr[i-1]<<","<<arr[i]<<")"<<endl;
		}
	}
}
int main(){
	int n;
	
	cout<<"enter the size of array :";
	cin>>n;
	int arr[n];
	cout<<"enter the elements of array :";
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	mindiff(arr,n);
	return 0;
}
