#include<stdio.h>

#define max_size 50
int q[max_size];
int front = -1 ;
int rear = -1;
enqueue()
{
int x,y;

 if((rear +1)% max_size == front)
{
printf("queue is overflown \n");

}

else
{
printf("enter the items to be added\n");
scanf("%d %d",&x,&y);
rear = (rear+1)% max_size;
front = (front -1)% max_size ;
q[rear] = x;
q[front]= y;
}


}
int dequeue()
{
 if(front == -1 && rear == -1)
{
printf("queue is underflown\n");
return ;
}
else if(front == rear)
{
front = rear = -1 ;
}
else
{
printf("element removed is %d\n",q[rear],q[front]);
rear = (rear-1)% max_size;
front = (front +1)% max_size ;
return;
}
}
int Front()
{
if(front == -1 && rear == -1)
{
printf("queue is underflown\n");
return ;
}
return q[front];
}
int Rear()
{
if(front == -1 && rear == -1)
{
printf("queue is underflown\n");
return ;
}
return q[rear];
}
void display()
{
int i ;
if(front == -1 && rear == -1)
{
printf("queue is underflown\n");
return ;
}
else{
front = 0;
printf("queue is :\n");
for(i = front; i <=rear;i++)
{
printf("%d\n",q[i]);
}
printf("\n");
}
}
int isFull()
{

if((rear +1)% max_size == front)
{
printf("queue is full \n");

}
return;
}
int isEmpty()
{

if(front == -1 && rear == -1)
{
printf("queue is empty\n");
return ;
}

}
 main()
{
   int choice;


   while (1)
   {
   printf("1 -> to add\n");
   printf("2 -> to remove\n");
   printf("3 -> front element\n");
   printf("4 -> rear element\n");
   printf("5 -> print elements\n");
   printf("6 -> isFull\n");
   printf("7 -> isEmpty\n");
   printf("8 -> quit\n");
   printf("enter ur choice\n");
   scanf("%d",&choice);

switch(choice)
{
case 1 :
{
enqueue();
break;
}
case 2 :
{
dequeue();
break;
}
case 3 :
{
printf("front item is ->%d\n",Front());
break;
}
case 4 :
{
printf("rear item is ->%d\n",Rear());
break;
}
case 5 :
{
display();
break;
}
case 6 :
{
isFull();
break;
}
case 7 :
{
isEmpty();
break;
}
case 8 :
{
exit(1);

}
default :
{
printf("invalid choice\n");

}

}
}

}
