#include<iostream>
using namespace std;

void merge(int a[],int l,int m,int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]= a[l+i];
	}
	for(j=0;j<n2;j++){
		R[j]=a[m+1+j];
	}
	i=0;
	j=0;
	k=1;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
			a[k]=L[i];
			i++;
			k++;
	}
	while(j<n2){
			a[k]=R[j];
			j++;
			k++;
	}

}

void mergesort(int a[],int l,int r){
	if(l<r){
	int m = l+(r-1)/2;
	
	mergesort(a,l,m);
	mergesort(a,m+1,r);
	
	merge(a,l,m,r);
	}	

}
int main()
{
    int a[] = {12, 11, 13, 5, 6, 7};
    int a_size = sizeof(a)/sizeof(a[0]);

    mergesort(a, 0, a_size - 1);
 
    cout<<"Sorted array is "<<endl;
    int i;
    for(i=0;i<a_size;i++){
		cout<<a[i]<<" ";
	}
    
    return 0;
}
/*
int main(){

	int n,i;
	int a[100];
	cout<<"enter the size of array :";
	cin>>n;
	cout<<"enter the elements :"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	cout<<"sorted array is:"<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
*/
