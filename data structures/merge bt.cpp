#include<iostream>

using namespace std;
struct Tree{
	int data;
	Tree* left;
	Tree* right;
};
struct Tree* newNode(int data){
	struct Tree* node = new Tree;
	node->data = data;
	node->left=node->right = NULL;
}
int *merge(int a1[],int a2[],int m,int n){
	int *mergeda = new int[m+n];
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(a1[i]<a2[j]){
		mergeda[k]=a1[i];
		i++;
		}
		else{
			mergeda[k]=a2[j];
		j++;
		}
		k++;
	}
	while(i<m){
		mergeda[k]=a1[i];
		i++,k++;
	}
	while(j<n){
		mergeda[k]=a2[j];
		j++,k++;
	}
	return mergeda;
}

void sinorder(struct Tree* node,int in[],int* index){
	if(node==NULL){
		return;
	}
	sinorder(node->left,in,index);
	in[*index] = node->data;
	(*index)++;
	sinorder(node->right,in,index);
}

struct Tree* tobst(int a[],int s,int e ){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	struct Tree* root = newNode(a[mid]);
	root->left= tobst(a,s,mid-1);
	root->right= tobst(a,mid+1,e);
	
	return root;
}
struct Tree* mergetrees(struct Tree* r1,struct Tree* r2,int m,int n){
	int *a1 = new int[m];
	int i=0;
	sinorder(r1,a1,&i);
	
    int *a2 = new int[n];
	int j=0;
	sinorder(r2,a2,&j);
	
	int *mergeda = merge(a1,a2,m,n);
	
	return tobst(mergeda,0,m+n-1);
}
void printInorder(struct Tree* node)
{
    if (node == NULL)
        return;
 

    printInorder(node->left);
    cout<< node->data<<" ";
    printInorder(node->right);
}

int main()
{

    struct Tree *root1  = newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);

    struct Tree *root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);
 
    struct Tree *mergedtree = mergetrees(root1, root2, 5, 3);
 
    cout<<"Following is Inorder traversal of the merged tree "<<endl;
    printInorder(mergedtree);
    return 0;
}










