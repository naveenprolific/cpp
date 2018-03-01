#include <iostream>

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
int idTrees(struct Tree* a, struct Tree* b){
	if(a == NULL && b== NULL)
	{
		return 1;
	}
	else if(a!= NULL && b!= NULL)
	{
		return{
		a->data == b->data &&
		idTrees(a->left,  b->left)&&
		idTrees(a->right,  b->right)
		};
	}
	else return 0;
	
}
int main()
 {
 struct Tree *root1 = newNode(1);
    struct Tree *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 
 
    if(idTrees(root1, root2))
        printf("Both trees are identical.");
    else
        printf("Trees are not identical.");
 
	 
    return 0;
}
