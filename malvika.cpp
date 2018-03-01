#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	string str;
	getline(cin, str);
	int n=str.length();
	char a[n+1];
	strcpy(a,str.c_str());
	cout<<min(count(a,a+n+1,'a'),count(a,a+n+1,'b'))<<endl;
	}
	return 0;
}
