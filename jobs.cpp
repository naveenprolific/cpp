#include<bits/stdc++.h>
using namespace std;
struct job{
	int id;
	int dead;
	int p;
};
bool comp(struct job a,struct job b){
	return a.p>b.p;
}
int profit(struct job a[],int n){
	sort(a,a+n,comp);
	int res[n];
	bool slot[n];
	for(int i=0;i<n;i++){
		slot[i]=false;
	}
	for(int i=0;i<n;i++){
		for(int j=min(n,a[i].dead)-1;j>=0;j--){
	if(slot[j]==false){
		res[j]=i;
		slot[j]=true;
		break;
	}
	}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(slot[i]){
			sum+=a[res[i]].p;
		}
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	struct job a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].id;
		cin>>a[i].dead;
		cin>>a[i].p;
	}
	cout<<profit(a,n);
	return 0;
}
