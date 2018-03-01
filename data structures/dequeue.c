#include<stdio.h>

#define max_size 50
int q[max_size];
int front = 0 ;
int rear = -1;
enqueueR()
{
int x;

 if((rear +1)% max_size == front-1)
{
printf("queue is overflown \n");

}

else
{
printf("enter the  rear item  to be added\n");
scanf("%d",&x);
rear = (rear+1)% max_size;
q[rear] = x ;

}
}
enqueueF()
{
int y;

 if((rear +1)% max_size == front-1)
{
printf("queue is overflown \n");

}

else
{
printf("enter the  front item to be added\n");
scanf("%d",&y);

front = (front -1)% max_size ;

q[front]= y;
}

}
int dequeueR()
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
printf("elements removed is  %d\n",q[front]);

front = (front +1)% max_size ;
return;
}
}

int dequeueF()
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
printf("elements removed is  %d\n",q[rear]);
rear = (rear-1)% max_size;

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
 
 printf("Queue elements :\n");
    for(i =front;i <=rear;i++)
{
printf("%d\n",q[i]);
}
    printf("\n");

}
}
int isFull()
{

if((rear +1)% max_size == front-1)
{
printf("queue is full \n");

}
else
{
	printf("queue is not full\n");
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
else
{
	printf("queue is not empty\n");
	return ;
}
}
 main()
{
   int choice;


   while (1)
   {
   printf("1 -> to add rear\n");
   printf("2 -> to add front\n");
   printf("3 -> to remove rear\n");
   printf("4 -> to remove front\n");
   printf("5 -> front element\n");
   printf("6 -> rear element\n");
   printf("7 -> print elements\n");
   printf("8 -> isFull\n");
   printf("9 -> isEmpty\n");
   printf("10 -> quit\n");
   printf("enter ur choice\n");
   scanf("%d",&choice);

switch(choice)
{
case 1 :
{
enqueueR();
break;
}
case 2 :
{
enqueueF();
break;
}
case 3 :
{
dequeueR();
break;
}
case 4 :
{
dequeueF();
break;
}
case 5 :
{
printf("front item is ->%d\n",Front());
break;
}
case 6 :
{
printf("rear item is ->%d\n",Rear());
break;
}
case 7 :
{
display();
break;
}
case 8 :
{
isFull();
break;
}
case 9 :
{
isEmpty();
break;
}
case 10 :
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
