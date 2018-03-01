#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *link;    
}*top;
class stack
{
    public:
        node *push(node *, int);
        node *pop(node *);
        void display(node *);
        stack_list()
        {
            top = NULL;
        }               
};
int main()
{
    int choice, item;
    stack sl;
    while (1)
    {
        cout<<"1.Push Element into the Stack"<<endl;
        cout<<"2.Pop Element from the Stack"<<endl;
        cout<<"3.display the Stack"<<endl;
        cout<<"4.Quit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be pushed into the stack: ";
            cin>>item;
            top = sl.push(top, item);
            break;
        case 2:
            top = sl.pop(top);
            break;
        case 3:
            sl.display(top);
            break;
        case 4:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
node *stack::push(node *top, int item)
{
    node *tmp = new (struct node);
    tmp->data = item;
    tmp->link = top;
    top = tmp;
    return top;
}
node *stack::pop(node *top)
{
    node *tmp;
    if (top == NULL)
        cout<<"Stack is Empty"<<endl;
    else
    {       
        tmp = top;
        cout<<"Element Popped: "<<tmp->data<<endl;
        top = top->link;
        delete(tmp);
    }
    return top;
}
void stack::display(node *top)
{       
    node *ptr;
    ptr = top;
    if (top == NULL)
        cout<<"Stack is empty"<<endl;
    else
    {
        cout<<"Stack elements :"<<endl;
        while (ptr != NULL)
        {
            cout<<ptr->data<<endl;
            ptr = ptr->link;
        }
    }
}
