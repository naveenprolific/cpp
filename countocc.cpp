#include<bits/stdc++.h>
using namespace std;
int count(int poly[],int n,int x){
	int res= 0;
	for(int i=0;i<n;i++){
		if(x==poly[i]){
			res+=1;
		}	
	}
	return res;
}
int main(){
	int n,x;
	cout<<"enter the num of elmts of arr ";
	cin>>n;
	int poly[n];
	cout<<"enter the elemts :";
	for(int i=0;i<n;i++){
		cin>>poly[i];
	}
	cout<<"enter the value of x :";
	cin>>x;
	cout << "count is : " << count(poly, n, x);
    return 0;
}
