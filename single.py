#include<bits/stdc++.h>
using namespace std;
void search(int arr[],int l,int h){
	if(l>h){
		return;
	}
	if(l==h){
		cout<<"element is "<<arr[l];
		return;
	}
	int mid=(l+h)/2;
	if(mid%2==0){
		if (arr[mid] == arr[mid+1]){
		
            search(arr, mid+2, high);}
        else{
        	 search(arr, low, mid);
		}    
	}
	else{
		if (arr[mid] == arr[mid-1]){
		
            search(arr, mid-2, high);}
        else{
        	 search(arr, low, mid-1);
		}  
	}
}
int main(){
	int n;
	cout<<"enter the size of array"<<endl;
	int arr[n];
	cout<<"enter the elements of array";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	search(arr,0,n-1);
	return 0;
}
