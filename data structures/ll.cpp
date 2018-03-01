#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head;
class single_llist
{
    public:
        node* create_node(int);
        void insert_begin();
        void insert_pos();
        void insert_last(); 
        void delete_pos();
        void sort();
        void search();
        void update();
        void reverse();
        void display();
        void nfe(node*,int);
        int nfb(node*,int);
        int len(node*);
        void swapk(node*,int);
        void middle(node*);
        node* reverseg(node*,int);
        void deletealt(node*);
        void rotate(node*,int);
        void EO(node*);
        node* kAltReverse( node*, int );
        single_llist() 
        {
            head = NULL;
        }
};
main()
{
    int choice, nodes, element, position, i,n,m,k,x,y,z;
    single_llist sl;
    head= NULL;
    while (1)
    {
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Display Linked List"<<endl;
        cout<<"9.Reverse Linked List "<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"11.nth node from end"<<endl;
        cout<<"12.nth node from beginning "<<endl;
        cout<<"13.length of linked list "<<endl;
        cout<<"14.swap kth node from begin and end"<<endl;
        cout<<"15.middle element "<<endl;
        cout<<"16.revrse ll in groups"<<endl;
        cout<<"17.delete alternate nodes "<<endl;
        cout<<"18.rotate linked list "<<endl;
        cout<<"19.segregation... "<<endl;
        cout<<"20.reverse alternate k nodes .."<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Sort Link List: "<<endl;
            sl.sort();
            cout<<endl;
            break;
        case 5:
            cout<<"Delete a particular node: "<<endl;
            sl.delete_pos();
            break;
        case 6:
            cout<<"Update Node Value:"<<endl;  
            sl.update();
            cout<<endl;
            break;
        case 7:
            cout<<"Search element in Link List: "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 8:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 9:
            cout<<"Reverse elements of Link List"<<endl;
            sl.reverse();
			sl.display();
            cout<<endl;
            break;
        case 10:
            cout<<"good bye..tataaa..."<<endl;
            exit(1);
            break;  
        case 11:
        	cout<<"enter the position of node  from end ->";
        	cin>>n;
        	sl.nfe(head,n);
        case 12:
        	cout<<"enter the index of node -->";
        	cin>>m;
        	sl.nfb(head,m);
        	break;
        case 13:
        	cout<<"length of linked list is :"<<endl;
        	sl.len(head);
        	break;
        case 14:
        	cout<<"enter the position of node  to swap ->";
        	cin>>k;
        	sl.swapk(head,k);
        	cout<<"after swapping"<<endl;
        	sl.display();
        	break;
        case 15:
        	sl.middle(head);
        	break;
        case 16:
        	cout<<"enter the size of grps ->";
        	cin>>x;
        	sl.reverseg(head,x);
        	cout<<"after reversing"<<endl;
        	sl.display();
        	break;
        case 17:
        	sl.deletealt(head);
        	cout<<"after deletion of alternate nodes "<<endl;
        	sl.display();
        	break;
        case 18:
        	cout<<"enter the k value ->";
        	cin>>y;
        	sl.rotate(head,y);
        	cout<<"after rotating"<<endl;
        	sl.display();
        	break;
        case 19: 
            sl.EO(head);
            cout<<"new list ...."<<endl;
            sl.display();
            break;
        case 20:
        	cout<<"enter the k value ->";
        	cin>>z;
        	sl.kAltReverse(head,z);
        	cout<<"after revrsing"<<endl;
        	sl.display();
        	break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
node *single_llist::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->data = value;
        temp->next = NULL;     
        return temp;
    }
}
void single_llist::insert_begin()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;          
    } 
    else
    {
        p = head;
        head = temp;
        head->next = p;
    }
}
void single_llist::insert_last()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s;
    temp = create_node(value);
    s = head;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;  
}
void single_llist::insert_pos()
{
    int value, pos, counter = 0; 
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    cout<<"Enter the postion at which node to be inserted: ";
    cin>>pos;
    int i;
    s = head;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (head == NULL)
        {
            head = temp;
            head->next = NULL;
        }
        else
        {
            ptr = head;
            head = temp;
            head->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = head;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        cout<<"Positon out of range"<<endl;
    }
}
void single_llist::sort()
{
    struct node *ptr, *s;
    int value;
    if (head == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = head;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->data > s->data)
            {
                value = ptr->data;
                ptr->data = s->data;
                s->data = value;
            }
        }
        ptr = ptr->next;
    }
}
void single_llist::delete_pos()
{
    int pos, i, counter = 0;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    struct node *s, *ptr;
    s = head;
    if (pos == 1)
    {
        head = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = head;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}
void single_llist::update()
{
    int value, pos, i;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node postion to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *s, *ptr;
    s = head;
    if (pos == 1)
    {
        head->data = value; 
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->data = value;  
    }
    cout<<"Node Updated"<<endl;
}
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct node *s;
    s = head;
    while (s != NULL)
    {
        pos++;
        if (s->data == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;  
}
void single_llist::reverse()
{
   struct node *ptr1, *ptr2, *ptr3;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (head->next == NULL)
    {
        return;
    }  
    ptr1 = head;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    head = ptr2;
    
}
void single_llist::display()
{
    struct node *temp;
    if (head == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = head;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void single_llist :: nfe(struct node* head,int n){
	int l= 0,i;
	struct node* temp = head;
	while(temp!=NULL){
		temp = temp->next;
		l++;
	}
	if(l<n){
		return;
	}
   temp = head;
	for(i=1;i<l-n+1;i++){
		temp=temp->next;
	}
	cout<<n<<" node from end is :->|"<<temp->data<<"|"<<endl;
	return;
}
int single_llist :: nfb(struct node* head, int n){
	int l=0,i;
	struct node* temp = head;
	while(temp!=NULL){
		if(l==n){
			cout<<n<<" node from beginning is :->|"<<temp->data<<"|"<<endl;
		}
		temp = temp->next;
		l++;
	}
   return 0;
}
int single_llist :: len(struct node* s){
	int l =0;
	struct node* temp = s;
	while(temp!= NULL){
		temp=temp->next;
		l++;
	}
return l;
}
void single_llist :: swapk(struct node* head,int k){
	int i,n=0;
	struct node* temp1 = head;
	while(temp1!= NULL){
		temp1=temp1->next;
		n++;
	}
	
	 if(n<k){return;}
	 if(2*k-1 == n){return;}
	 node* x = head;
	 node* xprev = NULL;
	for(i=1;i<k;i++){
		xprev = x;
	   	x =x->next;
	}
	node* y = head;
	node* yprev = NULL;
	for(i=1;i<n-k+1;i++){
		yprev = y;
	   	y =y->next;
	}
	if(xprev){
		xprev->next=y;
	}
	if(yprev){
		yprev->next=x;
	}
	node* temp = x->next;
	x->next = y->next;
	y->next = temp;
	if(k==1){
		head = y;
	}
	if(k==n){
		head = x;
	}
}
void single_llist :: middle(struct node* head){
	node* fast =head;
	node* slow = head;
	if(head!=NULL){
		while(fast!=NULL&&fast->next!=NULL){
			fast = fast->next->next;
			slow=slow->next;
		}
		cout<<"midlle element is -> "<<slow->data<<endl;
	}
}
node* single_llist :: reverseg(struct node* head,int k){
	struct node* current = head ;
	struct node* nxt = NULL;
	struct node* prev = NULL;
	int count = 0;
	while(current!=NULL && count < k){
		nxt = current->next;
		current->next = prev;
		prev = current;
		current = nxt;
		count++;
	}
	if(nxt!= NULL){
		head->next=reverseg(nxt,k);
	}
	return prev;
}
void single_llist :: deletealt(struct node* head){
	if(head==NULL){
		return;
	}
	struct node* prev = head;
	struct node* temp = head->next;
	while(prev!=NULL&&temp!=NULL){
		prev->next= temp->next;
		delete(temp);
		prev = prev->next;
		if(prev!=NULL){
			temp = prev->next;
		}
	}
}
void single_llist :: rotate(struct node* head,int k){
	if(k==0){
		return;
	}
	struct node* current = head;
	int count = 1;
	while(count<k && current!=NULL){
		current = current->next;
		count++;
	}
	if(current==NULL){
		return;
	}
	struct node* knode = current;
	struct node* temp = head;
		while(temp->next!=NULL){
		temp = temp->next;
      }
	temp->next =head;
	head = knode->next;
	knode->next = NULL;
}
void single_llist :: EO(struct node* head){
	struct node* end = head;
	struct node* curr = head;
	struct node* prev = NULL;
	
	while(end->next!=NULL){
		end = end->next;
	}
	struct node* newend  = end;
	while((curr->data)%2 != 0 && curr!= end){
		newend->next = curr;
	    curr =curr->next ;
	    newend->next->next = NULL;
	    newend = newend->next;
	}
	
	if((curr->data)%2 ==0){
		head = curr;
		while(curr!=end){
			if((curr->data)%2 ==0){
				prev = curr ;
				curr = curr->next;
			}
			else{
				prev->next = curr->next;
				curr->next = NULL;
				newend->next = curr;
				newend = curr;
				curr = prev->next;
			}
		}
	}
	
	else prev = curr;
    if (newend!=end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        newend->next = end;
    }
    return;
}
 node* single_llist ::kAltReverse(struct node *head, int k)
{
    struct node* current = head;
    struct node* nxt;
    struct node* prev = NULL;
    int count = 0; 
    while (current != NULL && count < k)
    {
       nxt  = current->next;
       current->next = prev;
       prev = current;
       current = nxt;
       count++;
    }
    if(head != NULL)
      head->next = current; 
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }
    if(current !=  NULL)
       current->next = kAltReverse(current->next, k);
    return prev;
}
