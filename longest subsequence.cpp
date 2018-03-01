#include<bits/stdc++.h>
using namespace std;
void mincoins(int a[],int n){
	vector<int> res;
	int lis[n];
	int i,j,max=0;
	for(i=0;i<n;i++){
		lis[i]=1;
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]>a[j]&&lis[i]<lis[j]+1){
				lis[i]=lis[j]+1;
				res.push_back(a[i]);
			}
		}
	}
	for(i=0;i<n;i++){
		if(max<lis[i]){
			max=lis[i];
		}
	}
	cout<<"max sequence length is :"<<max<<endl;

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
