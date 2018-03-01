#include<bits/stdc++.h>
using namespace std;
struct box{
	int h,w,d;
};
int max(int a,int b){
	return (a>b)?a:b;
}
int min(int a,int b){
	return (a<b)?a:b;
}
bool comp(struct box a,struct box b){
	return (a.d*a.w)>(b.d*b.w);
}
void mincoins(struct box a[],int n){
	struct box res[3*n];
	int i,j=0,m=-1;
	for(i=0;i<n;i++){
		res[j]=a[i];
		j++;
		res[j].h=a[i].w;
		res[j].d=max(a[i].h,a[i].d);
		res[j].w=min(a[i].h,a[i].d);
		j++;
		res[j].h=a[i].d;
		res[j].d=max(a[i].h,a[i].w);
		res[j].w=min(a[i].h,a[i].w);
		j++;
	}
	n=3*n;
	sort(res,res+n,comp);
	int mh[n];
	for(int i=0;i<n;i++){
		mh[i]=res[i].h;
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(res[i].w<res[j].w&&res[i].d<res[j].d&&mh[i]<mh[j]+res[j].h){
				mh[i]=mh[j]+res[j].h;
			}
		}
	}
	for(i=0;i<n;i++){
		if(m<mh[i]){
			m=mh[i];
		}
	}
	cout<<"max  hgt is :"<<m<<endl;

}
int main(){
	int n;
	cin>>n;
	struct box a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].h;
		cin>>a[i].w;
		cin>>a[i].d;
	}
	mincoins(a,n);
	return 0;
}
