#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
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
int LevelDiff(struct Tree* node){
	if(node == NULL){
		return 0;
	}
	return node->data - LevelDiff(node->left) - LevelDiff(node->right);
	
}
void Delete(struct Tree* node)
{
	  if(node == NULL){
	  	return ;
	  }
	  Delete(node->left);
	  Delete(node->right);
	 cout<<"deleteing node  "<<node->data<<endl;
    delete(node);
	  
}
void pleaves(struct Tree* node){
	if(node){
		pleaves(node->left);
		if ( !(node->left)  &&  !(node->right) ){
		
	cout<<node->data<<endl;
	}
		pleaves(node->right);	
	}

}
void pleftb(struct Tree* node){
	if(node){
		if(node->left){
				cout<<node->data<<endl;
				pleftb(node->left);
		}
		else if(node->right){
		cout<<node->data<<endl;
				pleftb(node->right);
		}
	}
}
void prightb(struct Tree* node){
	if(node){
		if(node->right){
			cout<<node->data<<endl;
				prightb(node->right);
		}
		else if(node->left){
				cout<<node->data<<endl;
				prightb(node->left);
		}
	}
	
}
void pb(struct Tree* node){
	if(node){
		cout<<node->data<<endl;
		pleftb(node->left);
		pleaves(node->left);
		pleaves(node->right);
		prightb(node->right);
	}
}
int leafcount(struct Tree* node){
	if(node==NULL){
		return 0;
	}
	if(node->left == NULL && node->right == NULL)
	{
		return 1;
	}
	else return leafcount(node->left)+leafcount(node->right);
}
struct Tree* lca(struct Tree* node,int n1,int n2){
	if(node== NULL)
	{
		return NULL;
	}
	if(node->data == n1 && node->data == n2){
		return node;
	}
    Tree* leftlca = lca(node->left,n1,n2);
    Tree* rightlca = lca(node->right,n1,n2);
    if(leftlca && rightlca)
    {
    	return node;
	}
	return (leftlca != NULL)? leftlca: rightlca;
}
void dtree(struct Tree* node){
	struct Tree* oldleft;
	if(node==NULL){
		return;
	}
	dtree(node->left);
	dtree(node->right);
	oldleft = node->left;
	node->left = newNode(node->data);
	node->left->left = oldleft;
}
void mirror(struct Tree* node){
	if(node== NULL){
		return;
	}
	struct Tree* temp;
	
	mirror(node->left);
	mirror(node->right);
	
	temp = node->left;
	node->left = node->right;
	node->right = temp;
}
int sum(struct Tree* node){
	if(node== NULL){return 0;}
	return sum(node->left) + node->data + sum(node->right);
}
bool issumtree(struct Tree* node){
	if(node == NULL || (node->left==NULL && node->right == NULL)){
		return true;
	}
	int ls = sum(node->left);
	int rs = sum(node->right);
	if((node->data == ls+rs)&&issumtree(node->left)&&issumtree(node->right)){
		return true;
	}
	return false;
}
bool isbst(struct Tree* node,struct Tree* l = NULL,struct Tree* r = NULL){
	if(node == NULL){
		return true;
	}
	if(l!= NULL && node->data< l->data){
		return false;
	}
	if(r!= NULL && node->data> r->data){
		return false;
	}
	return isbst(node->left,l,node)&&isbst(node->right,node,r);
}
int largestbst(struct Tree* node){
	if(isbst(node)){
		return Size(node);
	}
	return max(largestbst(node->left),largestbst(node->right));
}


bool mat[MAX][MAX];

int ancmatrec(struct Tree* node ,vector<int> &anc){
	if(node== NULL){
		return 0;
	}
	int data = node->data;
	for(int i = 0;i<anc.size();i++){
		mat[anc[i]][data] = true;
	}
	anc.push_back(data);
	int l = ancmatrec( node->left ,anc);
	int r = ancmatrec( node->right ,anc);
	anc.pop_back();
	
	return l+r+1;
}
int ancmat(struct Tree* node){
	vector<int> anc;
	
	int n = ancmatrec(node,anc);
	for(int i= 0;i<n;i++){
		for(int j= 0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool issame(struct Tree* a,struct Tree* b){
	if(a == NULL && b == NULL){
		return true;
	}
	if(a!=NULL && b!=NULL && issame(a->left,b->left)&&issame(a->right,b->right)){
		return true;
	}
	return false;
}
bool isfoldable(struct Tree* node){
	bool res;
	if(node== NULL){
		return true;
	}
	mirror(node->left);
	res = issame(node->left,node->right);
	mirror(node->left);
	return res;
}
struct Tree* removepathutil(struct Tree* node,int level,int k){
	if(node== NULL){
		return NULL;
	}
	node->left = removepathutil(node->left,level+1,k);
	node->right = removepathutil(node->right,level+1,k);
	
	if(node->left ==NULL && node->right ==NULL && level < k){
		delete node;
		return NULL;
	}
	return node;
}
struct Tree* removepath(struct Tree* node,int k){
	int pathlen = 0;
	return removepathutil(node,1,k);
}
void printa(int p[],int len){
	int i;
	for(i=0;i<len;i++){
		cout<<p[i]<<"->";
	}
	cout<<endl;
}
void pathrecur(struct Tree* node,int path[],int pathlen){
	if(node==NULL){
		return;
	}
	path[pathlen] = node->data;
	pathlen++;
	if(node->left==NULL && node->right==NULL){
		printa(path,pathlen);
	}
	else{
		pathrecur(node->left,path,pathlen);
		pathrecur(node->right,path,pathlen);
	}
}
void path(struct Tree* node){
	int path[100];
	pathrecur(node,path,0);
}
bool ancestors(struct Tree* node,int tg){
	if(node == NULL){
		return false;
	}
	if(node->data== tg){
		return true;
	}
	if(ancestors(node->left,tg)||ancestors(node->right,tg)){
		cout<<node->data<<" ";
		return true;
	}
	return false;
}

 int main()
 {
 	Tree *root        = newNode(5);
    root->left        = newNode(1);
    root->right       = newNode(2);
    root->left->left  = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(3);
 
  
  cout<<"ancestor matrix of given binary tree :"<<endl;
  ancmat(root);
    
    
    cout<<" Size of the largest BST is "<< largestbst(root)<<endl;
  cout<<"Maximum width is  "<< MaxWidth(root)<<endl;  
  cout<<"Size of the tree is "<< Size(root)<<endl; 
  cout<<"hgt of the tree is "<< hgt(root)<<endl; 
   cout<<"Diameter of the given binary tree is "<< dmt(root)<<endl;
   
   cout<<"Preorder traversal of binary tree is ";
     preorder(root);
 
     cout<<"Inorder traversal of binary tree is ";
     inorder(root);  
 
     cout<<"Postorder traversal of binary tree is ";
     postorder(root);
  
    cout<<"reverse levelorder traversal of binary tree is ";
     rlevelorder(root);
     
     cout<< LevelDiff(root)<<"  is the required difference"<<endl;
     
     cout<<"Leaf count of the tree is "<< leafcount(root)<<endl;
    
     cout<<"boundary nodes are :";
     pb(root);
     cout<<"after doubling the tree "<<endl;
     dtree(root);
     cout<<"given tree is mirrored "<<endl;
     mirror(root);
     int k = 4;
     removepath(root,k);
     
     cout<<"Maximum width is  "<< MaxWidth(root)<<endl;  
  cout<<"Size of the tree is "<< Size(root)<<endl; 
  cout<<"hgt of the tree is "<< hgt(root)<<endl; 
   cout<<"Diameter of the given binary tree is "<< dmt(root)<<endl;
   
   cout<<"Preorder traversal of binary tree is ";
     preorder(root);
 
     cout<<"Inorder traversal of binary tree is ";
     inorder(root);  
 
     cout<<"Postorder traversal of binary tree is ";
     postorder(root);
  
    cout<<"reverse levelorder traversal of binary tree is ";
     rlevelorder(root);
     
     cout<< LevelDiff(root)<<"  is the required difference"<<endl;
     
     cout<<"Leaf count of the tree is "<< leafcount(root)<<endl;
    
     cout<<"boundary nodes are :";
     pb(root);
      if(issumtree(root))
        cout<<"The given tree is a SumTree "<<endl;
    else
        cout<<"The given tree is not a SumTree "<<endl;
        
        if (isbst(root))
        cout << "Is BST"<<endl;
    else
        cout << "Not a BST"<<endl;
        if(isfoldable(root) == 1)
  { cout<<" tree is foldable"<<endl; }
  else
  { cout<<" tree is not foldable"<<endl; }
int tg = 3;
  cout<<"ancestors of "<<tg<<endl;
  ancestors(root,tg);
  cout<<endl;
  cout<<"paths of final tree : "<<endl;
  path(root);
     Delete(root);  
    root = NULL;
    cout<<" Tree deleted "<<endl;
  return 0;
 }
