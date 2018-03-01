#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};
 
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	 return (node);
}

int hgt(struct node* node)
{
	if(node== NULL)
	{
		return 0;
	}
	else{
		int lhgt = hgt(node->left);
		int rhgt = hgt(node->right);
		 
		 if(lhgt > rhgt){
		 	return (lhgt+1);
		 }
		else return (rhgt+1);
	}
}
 
void givenLevel(struct node* root,int level)
{
	if (root == NULL)
	{
		return;
	}
	if (level == 1)
	{
		printf("%d ",root->data);
	}
	else if(level >1)
	{
		givenLevel(root->left,level-1);
		givenLevel(root->right,level-1);
	}
}

void Levelorder(struct node* root)
{
	int h = hgt(root);
	int i;
	for(i=1;i<=h;i++)
	{
		givenLevel(root,i);
	}
}

void Inorder(struct node*  node)
{
	if(node == NULL ){
		return;
	}
	Inorder(node->left);
	printf("%d",node->data);
	Inorder(node->right);
}

void Postorder(struct node*  node)
{
	if(node == NULL ){
		return;
	}
    Postorder(node->left);
	
	Postorder(node->right);
	printf("%d",node->data);
}
void Preorder(struct node*  node)
{
	if(node == NULL ){
		return;
	}
	
    printf("%d",node->data);
	Preorder(node->left);

	Preorder(node->right);
}

int main()
{    
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 
    
     int h = hgt(root);
     printf("\n hght of binary tree is  % d\n",h);
     printf("\nPreorder traversal of binary tree is \n");
     Preorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     Inorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     Postorder(root);
 
     printf("\nLevelorder traversal of binary tree is \n");
     Levelorder(root);
     getchar();
     return 0;
}














