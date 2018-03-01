#include<bits/stdc++.h>
using namespace std;
int samecount(int a[],int n,int x,int y){
	int res=0;
	for(int i=0;i<=n-1;i++){
		int cx=0,cy=0;
		for(int j=i;j<=n-1;j++){
			if(a[j]==x){
				cx++;
			}
			if(a[j]==y){
				cy++;
			}
			if(cx==cy){
				res++;
			}
		}
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x,y;
	cin>>x;
	cin>>y;
	cout<<samecount(a,n,x,y);
	return 0;
}
