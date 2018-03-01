#include<bits/stdc++.h>
using namespace std;
int main(){
	long int n=1,k=1,j=0;
	long int arr[n],b[n+1];
	while(n!=0){
		cin>>n;
		if(n==0){
			break;
		}
		for(int i=0;i<n;i++){
		cin>>arr[i];
		}
		while(k<=n){
			b[arr[j]]=k;
			k++;
			j++;
		}
		if(b==arr){
			cout<<"ambiguous"<<endl;
		}
		else{
			cout<<"not ambiguous"<<endl;
		}
	}
	return 0;
}
