#include <iostream>
#include<climits>
using namespace std;

struct Tree{
	int data;
	Tree *left;
	Tree *right;
	Tree *parent;
};

struct Tree *newNode(int data)
{
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->parent = NULL;
	node->right = NULL;
	
	return (node);
}

int Size(struct Tree *node)
 {
 	if (node == NULL)
 	  {
	   return 0;
	  }
	else return (Size(node->left)+Size(node->right)+1);
 }
int hgt(struct Tree *node)
 {
 	if(node == NULL)
 	{
 		return 0;
	 }
	 else{
	 	int lhgt = hgt(node->left);
	 	int rhgt = hgt(node->right);
	 	
	 	if(lhgt > rhgt )
	 	{
	 		return (lhgt + 1);
		 }
		 else return (rhgt +1);
	 }
 	
 }
 int max(int a,int b)
{
	return (a >= b)? a: b;
}
int dmt(struct Tree *node){
	if(node == NULL){
		return 0;
	}
	int lhgt = hgt(node->left);
	int rhgt = hgt(node->right);
	
	int ldmt = dmt(node->left);
    int rdmt = dmt(node->right);
	
	return max(lhgt+rhgt+1,max(ldmt,rdmt));
}
int getWidth(struct Tree *node,int level){

	if(node== NULL){
		return 0;
	}
	if(level == 1){
		return 1;
	}
	else if(level > 1){
		return getWidth(node->left,level-1)+ getWidth(node->right,level-1);
	}
}

int MaxWidth(struct Tree *node){
	int maxwidth = 0;
	int width;
	int h = hgt(node);
	int i;
	for( i=0;i<=h;i++)
	{
	width = getWidth(node,i);
	if(width > maxwidth){
		maxwidth = width;
	}

	}
		return width;
}
 
struct Tree* insert(struct Tree* node,int data){
	if(node== NULL){
		return(newNode(data));
	}
	else{
		if(data<= node->data){
			node->left = insert(node->left,data);
		}
		else{
			node->right = insert(node->right,data);
		}
		
		return node;
	}
}
int inorder(struct Tree* node){
	if(node == NULL){
		return 0;
	}
    inorder( node->left);
	cout<<node->data<<endl;
	inorder( node->right);
}
int preorder(struct Tree* node){
	if(node == NULL){
		return 0;
	}
	cout<<node->data<<endl;
    preorder( node->left);
	
	preorder( node->right);
}
int postorder(struct Tree* node){
	if(node == NULL){
		return 0;
	}
    postorder( node->left);
	
	postorder( node->right);
    cout<<node->data<<endl;
}
void givenlevel(struct Tree* node,int level){
	if(node== NULL){
		return ;
	}
	if(level == 1){
	cout<<node->data<<endl;
	}
	else if(level > 1)
	{
		givenlevel( node->left,level-1);
		givenlevel( node->right,level-1);
	}
}

void rlevelorder(struct Tree* node){
	int h = hgt(node);
	int i;
	for(i =h; i>=1 ;i--){
		givenlevel(node,i);
	}
}
int  min(struct Tree* node){
	struct Tree* curr = node;
	while(curr->left != NULL){
		curr = curr->left;
	}
	return curr->data;
}
void newbst(struct Tree* node,int *sum){
	if(node == NULL){
		return;
	}
	newbst(node->right,sum);
	*sum = * sum + node->data;
	node->data = *sum;
	newbst(node->left,sum);
}
void modbst(struct Tree* node){
	int sum = 0; 
	newbst(node,&sum);
}
struct Tree* lca(struct Tree* node,int n1,int n2){
	if(node== NULL){
		return NULL;
	}
	if(node->data>n1 && node->data>n2){
		lca(node->left,n1,n2);
	}
	if(node->data<n1 && node->data<n2){
		lca(node->right,n1,n2);
	}
	return node;
}
void print(struct Tree* node,int k1,int k2){
	if(node == NULL){
		return ;
	}
	if(k1<node->data){
		print(node->left,k1,k2);
	}
	if(k1<=node->data && k2>=node->data){
		cout<<node->data<<endl;
	}
	if(k2>node->data){
		print(node->right,k1,k2);
	}
}
struct Tree* remove(struct Tree* node,int k1,int k2){
	if(node==NULL){
		return NULL;
	}
	node->left = remove(node->left,k1,k2);
	node->right = remove(node->right,k1,k2);
	if(node->data<k1){
		Tree*  rc = node->right;
		delete node;
		return rc;
	}
	if(node->data>k2){
		Tree*  lc = node->left;
		delete node;
		return lc;
	}
	return node;
}
int main()
{
  struct Tree* root = NULL;
  root = insert(root, 4);
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 6);
  insert(root, 5);  
  int k1 = 2,k2 = 5;
  print(root,k1,k2);
  remove(root,k1,k2);
    struct Tree* a = lca(root, 4, 5);
    struct Tree* b = lca(root, 4, 6);
    struct Tree* c = lca(root, 3, 4);
    struct Tree* d = lca(root, 2, 1);
    cout << "LCA(4, 5) = " << a->data<<endl;
    cout << "LCA(4, 6) = " << b->data<<endl;
    cout << "LCA(3, 4) = " << c->data<<endl;
    cout << "LCA(2, 1) = " << d->data<<endl;
    
  cout<<"Maximum width is  "<< MaxWidth(root)<<endl;  
  cout<<"Size of the tree is "<< Size(root)<<endl; 
  cout<<"hgt of the tree is "<< hgt(root)<<endl; 
  cout<<"Diameter of the given binary tree is "<< dmt(root)<<endl;
    cout<<"Preorder traversal of binary tree is "<<endl;
     preorder(root);
 
     cout<<"Inorder traversal of binary tree is "<<endl;
     inorder(root);  
 
     cout<<"Postorder traversal of binary tree is "<<endl;
     postorder(root);
  
    cout<<"reverse levelorder traversal of binary tree is "<<endl;
     rlevelorder(root);
     
    cout<<" Minimum value in BST is "<< min(root)<<endl;
     cout<<"bst modified "<<endl;
     modbst(root);
     cout<<"Preorder traversal of binary tree is "<<endl;
     preorder(root);
 
     cout<<"Inorder traversal of binary tree is "<<endl;
     inorder(root);  
 
     cout<<"Postorder traversal of binary tree is "<<endl;
     postorder(root);
  
    cout<<"reverse levelorder traversal of binary tree is "<<endl;
     rlevelorder(root);
     
    cout<<" Minimum value in BST is "<< min(root)<<endl;
 
  return 0;    
}
