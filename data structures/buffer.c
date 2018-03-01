#include<stdio.h>
#include<stdlib.h>
#define n 10

int rear=-1;
int front=-1;  

char buffer[10];
void produce()
{
	char x;
	if(isFull())
	{
		printf("buffer is full\n");
	}
	else
	{ 
		printf("enter the character\n");
        scanf("%s",&x); 	    
	 	rear=rear+1;
        buffer[rear]= x;
        
	}
}

int isFull()
{
	if(rear== n-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void consume()
{
	if(front == -1&& rear == -1)
	{
	    printf("buffer is empty\n");
	}
	
	else
	{
	
		front = front + 1 ;
		printf("the element is %c\n",buffer[front]);
	    ++front;
	}
}


void display()
{
int i ;
if(front == -1&& rear == -1)
{
printf("queue is underflown\n");
return ;
}
else{
printf("queue is :\n");
for(i = front; i <=rear;i++)
{
printf("%c\n",buffer[i]);
}
printf("\n");
}
}

 main()
{
	int choice;
	
	while(1)
	{
		printf("1->procedure\n2->consume\n3->display\n4->exit\n");
		printf("enter any choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				produce();
				break;
			case 2:
				consume();
				break;
			case 3:
				display();
				break;
		    case 4:
		    	exit(1);
		    	
			default:
				printf("enter a valid choice");
		}
	}


  
}


