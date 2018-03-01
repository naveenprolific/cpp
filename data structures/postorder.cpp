#include<stdlib.h>
#include<iostream>
#include<stack>

using namespace std;

struct Tree{
	int data;
	Tree* left;
	Tree* right;
};
struct Tree* newNode(int data){
	struct Tree* node = new Tree;
	node->data=data;
	node->left=node->right=NULL;
}
void postorder(struct Tree* node){
	if(node== NULL){
		return;
	}
	stack<Tree*> nodestack;
	nodestack.push(node);
	
	while(!nodestack.empty()){
		if(node->left){
			nodestack.push(node->left);
		}
		if(node->right){
			nodestack.push(node->right);
		}
		
		struct Tree* node = nodestack.top();
		cout<<node->data<<" ";
		nodestack.pop();
		
	}
}
int main()
{
    
  struct Tree *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  postorder(root);
  return 0;
}
