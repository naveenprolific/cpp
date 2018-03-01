#include<bits/stdc++.h>
using namespace std;
void maxheapify(int a[],int n,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2l;
	if(l<n&&a[l]>a[i]){
		largest=l;
	}
	else{
		largest=i;
	}
	if(r<n&&a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(a[i],a[largest]);
		maxheapify(a,n,largest);
	}
	
}
void buildmaxheap(int arr[],int n){
	for(int i=n/2-1;i>=0;i--){
		maxheapify(arr,n,i);
	}
}
void heapsort(int a[],int n){
	buildmaxheap(a,n);
	for(int i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		n--;
		maxheapify(a,n,0);
	}
}
int  heapmaximum(int arr[],int n){
	return arr[n-1];
}

int heapextractmax(int arr[],int n){
	if(n<1){
		cout<<"error"<<endl;
	}
	int max=arr[0];
	arr[0]=arr[n-1];
	n--;
	maxheapify(arr,n,0);
	return max;
}
void heapdel(int arr[],int n,int i){
	arr[i]=arr[n];
	n--;
	maxheapify(arr,n,i);
}
void heapincreasekey(int arr[],int i,int key){
	if(key<arr[i]){
		cout<<"error";
	}
	arr[i]=key;
	while(i>1&&arr[i/2]<arr[i]){
		swap(arr[i],arr[i/2]);
		i=i/2;
	}
}
void maxheapinsert(int arr[],int n, int key){
	n++;
	heapincreasekey(arr,n,key);
}
int main(){
	int n;
	cout<<"enter the array size: ";
	cin>>n;
	int a[n];
	cout<<"enter the array elmts :";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	heapsort(a,n);
	for(int i=n;i>0;i--){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"heap maximum is :"<<heapmaximum(a,n)<<endl;
	cout<<"heap extract max :"<<heapextractmax(a,n)<<endl;
  for(int i=n;i>0;i--){
		cout<<a[i]<<" ";
	}
	int k;
	cout<<"enter the key:";
	cin>>k;
	maxheapinsert(a,n,k);
	for(int i=n;i>0;i--){
		cout<<a[i]<<" ";
	}
	heapdel(a,n,3);
	for(int i=n;i>0;i--){
		cout<<a[i]<<" ";
	}
	return 0;
}
