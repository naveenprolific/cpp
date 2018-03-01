#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
 struct node * minValue(struct node* node)
 {
  struct node* current = node;
  while (current->left != NULL)
   {
    current = current->left;
  }
  return current;
}
 struct node * maxValue(struct node* node)
 {
  struct node* current = node;
  while (current->right != NULL)
   {
    current = current->right;
  }
  return current;
}
 
struct node * Successor(struct node *root, struct node *n)
{
  if( n->right != NULL )
    return minValue(n->right);
  struct node *p = n->parent;
  while(p != NULL && n == p->right)
  {
     n = p;
     p = p->parent;
  }
  return p;
}

struct node * Predeccessor(struct node *root, struct node *n)
{
  if( n->left != NULL )
    return maxValue(n->left);
  struct node *p = n->parent;
  while(p != NULL && n == p->left)
  {
     n = p;
     p = p->parent;
  }
  return p;
}

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  node->parent = NULL;
   
  return(node);
}
struct node* insert(struct node* node, int data)
{
  if (node == NULL)
    return(newNode(data));
  else
  {
    struct node *temp;  
    if (data <= node->data)
    {    
         temp = insert(node->left, data);
         node->left  = temp;
         temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    }    
    return node;
  }
} 
  

int main()
{
  struct node* root = NULL, *temp, *succ,*pred, *min;
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);  
  root = insert(root, 14);    
  temp = root->left->right->left;
 
  succ =  Successor(root, temp);
  if(succ !=  NULL)
    printf("\n  Successor of %d is %d ", temp->data, succ->data);    
  else
    printf("\n  Successor doesn't exit");
 
 pred =  Predeccessor(root, temp);
  if(pred !=  NULL)
    printf("\n Predeccessor of %d is %d ", temp->data, pred->data);    
  else
    printf("\n  Predeccessor doesn't exit");
 
  getchar();
  return 0;
}
