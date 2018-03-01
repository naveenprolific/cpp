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
	stack<Tree*> nodestack1;
	stack<Tree*> nodestack2;
	struct Tree* node1 = new Tree;
	nodestack1.push(node);
	while(!nodestack1.empty()){
		
    	node1 = nodestack1.pop();
		nodestack2.push(node1);
		
		if(node->left){
			nodestack1.push(node->left);
		}
		if(node->right){
			nodestack1.push(node->right);
		}
		
	}
	 while (!nodestack2.empty())
    {
         node1 = nodestack2.pop();
        cout<<node->data<<" ";
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
