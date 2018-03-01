#include<stdio.h>

#define max_size 50
int q[max_size];

 
int front = -1 ;
int rear = -1;
enqueue()
{
int x;

 if(rear == max_size-1 )
{
printf("queue is overflown \n");

}

else
{	
printf("enter the item to be added\n");
scanf("%d",&x);
rear = rear+1;
q[rear] = x;

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
printf("element removed is %d\n",q[front]);
front = front +1 ;
return;
}
}
int Front()
{
	front = 0;
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
printf("queue is :\n");
for(i =front;i <=rear;i++)
{
printf("%d\n",q[i]);
}
printf("\n");
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
   printf("5 -> print elments\n");
   printf("6 -> quit\n");
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
exit(1);

}
default :
{
printf("invalid choice");

}

}
}

}
