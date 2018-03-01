#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void givenlevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {
        givenlevel(root->left, level-1);
        givenlevel(root->right, level-1);
    }
}
int hgt(struct node* temp)
{
    if (temp==NULL)
        return 0;
    else
    {
        
        int lheight = hgt(temp->left);
        int rheight = hgt(temp->right);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
   	printf("%d ", root->key);
       preorder(root->left);
        
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        
        postorder(root->right);
        printf("%d ", root->key);
    }
}
void levelorder(struct node *root)
{
    int h = hgt(root);
    int i;
    for(i=1;i<=h;i++)
    {
    	givenlevel(root,i);
	}
}

struct node* insert(struct node* node, int key)
{
    
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key); 
    return node;
    
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{ 
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int h = hgt(root);
    printf(" hgt is   %d",h);
    printf("\nPreorder traversal of binary tree is\n ");
    preorder(root);
 
    printf("\nInorder traversal of binary tree is \n");
     inorder(root);  
 
    printf("\nPostorder traversal of binary tree is \n");
     postorder(root);
     printf("\nlevelorder traversal of binary tree is \n");
    levelorder(root);
    
    printf("\nDeleted 20\n");
    root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree \n");
    inorder(root);
    printf("\nlevelorder traversal of binary tree is \n");
    levelorder(root);
    return 0;
}





































