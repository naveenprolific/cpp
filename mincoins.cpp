#include<bits/stdc++.h>
using namespace std;
void mincoins(int a[],int n,int v){
	vector<int> res;
	for(int i=n-1;i>=0;i--){
		while(v>=a[i]){
			v-=a[i];
			res.push_back(a[i]);
		}
	}
	int c=0;
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<"  ";
		c++;
	}
	cout<<endl;
	cout<<"num of coins :"<<c;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int v;
	cin>>v;
	mincoins(a,n,v);
	return 0;
}
