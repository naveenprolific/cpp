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

void preorder(struct Tree* node)
{
    if (node == NULL)
        return;
 
    cout<< node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a)/sizeof(a[0]);
 

    struct Tree *root = tobst(a, 0, n-1);
    cout<<" PreOrder Traversal of constructed BST "<<endl;
    preorder(root);
 
    return 0;
}











