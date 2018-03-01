#include<bits/stdc++.h>
using namespace std;
int horner(int poly[],int n,int x){
	int res=poly[0];
	for(int i=1;i<n;i++){
		res=res*x+poly[i];
		
	}
	return res;
}
int main(){
	int n,x;
	cout<<"enter the num of elmts of poly ";
	cin>>n;
	int poly[n];
	cout<<"enter the elemts :";
	for(int i=0;i<n;i++){
		cin>>poly[i];
	}
	cout<<"enter the value of x :";
	cin>>x;
	cout << "Value of polynomial is " << horner(poly, n, x);
    return 0;
}
