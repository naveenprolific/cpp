#include<stdio.h>


struct node{
	int data;
	 struct node* left;
	 struct node* right;
};
 struct node* node = (struct node*)malloc(sizeof(struct node))  ;
struct node* newNode(int data)
{
	
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}
int main()
{
	
	 struct node* root = newNode(1);
	
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->right = newNode(4);
	getchar();
	return 0;
	
}
