#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int p=0,q=0;
		int n=s.length();
		for(int i=0;i<n;i++){
			if(s[i]=='a'){
				p++;
			}
			else{
				q++;
			}
		}
		cout<<min(p,q)<<endl;
	}
	return 0;
}
