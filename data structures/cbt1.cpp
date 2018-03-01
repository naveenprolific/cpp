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
struct Tree* treeutil(int pre[],char preln[],int* preindex,int x){
	int index = *preindex;
	if(*preindex == x){
		return NULL; 
	}
	struct Tree* root = newNode(pre[*preindex]);
	(*preindex)++;
	
	if(preln[index]== 'N'){
		root->left = treeutil(pre,preln,preindex,x);
		root->right = treeutil(pre,preln,preindex,x);
	}
	return root;
}
struct Tree* tree(int pre[],char preln[],int x){
	int index = 0;
	return treeutil(pre,preln,&index,x);
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
	struct Tree* root = NULL;
	int pre[] = {10, 30, 20, 5, 15};
    char preln[] = {'N', 'N', 'L', 'L', 'L'};
	int x = sizeof(pre)/sizeof(pre[0]);
	
	 root = tree(pre,preln,x);
	cout<<"inorder traversal of tree "<<endl;
	Inorder(root);
	
	return 0;
}
