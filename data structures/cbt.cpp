#include<iostream>
using namespace std;

struct Tree{
	int data;
	Tree* left;
	Tree* right;
	Tree* parent;
};

struct Tree* newNode(int data){
	Tree* node = new Tree;
	node->data = data;
	node->left = node->parent = node->right = NULL;
	return node;
}
struct Tree* treeutil(int pre[],int post[],int* preindex,int l, int h,int size){
	if(*preindex>= size || l>h){
		return NULL; 
	}
	struct Tree* root = newNode(pre[*preindex]);
	++*preindex;
	
	if(l==h){
		return root;
	}
	int i;
	for(i =l; i<=h;i++){
		if(pre[*preindex]== post[i]);
		     break;
	}
	if(i<=h){
		root->left = treeutil(pre,post,preindex,l,i,size);
		root->right = treeutil(pre,post,preindex,i+1,h,size);
	}
	return root;
}
struct Tree* tree(int pre[],int post[],int size){
	int preindex = 0;
	return treeutil(pre,post,&preindex,0,size-1,size);
}
void Inorder(struct Tree* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    cout<< node->data<<endl;
    Inorder(node->right);
}
 
int main(){
	int m,n,i;
	int pre[100],post[100];
	cout<<"enter the size of pre array :";
	cin>>m;
	for(i=0;i<m;i++){
		cin>>pre[i];
	}
	cout<<"enter the size of post array :";
	cin>>n;
	for(i=0;i<n;i++){
		cin>>post[i];
	}
	int size = sizeof(pre)/sizeof(pre[0]);
	struct Tree* root = tree(pre,post,size);
	cout<<"inorder traversal of tree "<<endl;
	Inorder(root);
	
	return 0;
}
