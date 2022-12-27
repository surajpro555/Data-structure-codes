#include<stdio.h>
#include<stdio.h>
#define max 5
int queue[max];
int rear=-1;
int front=-1;
int isEmpty()
{
   if(front==-1&&rear==-1)
   return 1;
   return 0;	
}
int isFull()
{
	if(rear==0&&front==max-1||front==rear+1)
	return 1;
	return 0;
}
void enqueue(int val)
{
	if(isFull())
	{
	printf("Queue is Full\n");
	return;
    }
	else if(isEmpty())
	{
	    front=0;
		rear=0;	
	}
	else
	rear=(rear+1)%max;
	queue[rear]=val;
}
void dequeue()
{
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	 front=(front+1)%max;
}
int getFront()
{
	if(isEmpty())
	return -1;
	return queue[front];
}
int getRear()
{
	if(isEmpty())
	return -1;
	return queue[rear];
}
void display()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		return;
	}
	int i;
	printf("Element of Queue:");
	for(i=front;i!=rear;i=(i+1)%max)
	{
		printf("|%d|",queue[i]);
	}
	printf("|%d|\n",queue[i]);
}
int main()
{
	int val,ch;
	printf("1.enqueue\n2.dequeue\n3.isEmpty\n4.isFull\n5.getFront\n6.getRear\n7.Display\n.8.Exit\n");
	do
	{
		printf("-----------------------\nEnter your option:");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1:
				printf("Enter a inserting element:");
				scanf("%d",&val);
				enqueue(val);
				display();
				break;
			case 2:	
			   dequeue();
			   break;
			case 3:
			   if(isEmpty())
			   printf("Queue is Empty\n");
			  else
			    printf("Queue is not empty\n");
				break;
			case 4:
			    if(isEmpty())
			   printf("Queue is Full\n");
			  else
			    printf("Queue is not Full\n");
				break;
			case 5:
			   if(getFront()==-1)
			    printf("Queue is Empty\n");
			   else
			    printf("Front Element of Queue:%d\n",getFront());
				break;
			case 6:
			   if(getRear()==-1)
			    printf("Queue is Empty\n");
			   else
			    printf("Rear Element of Queue:%d\n",getRear());
				break;
			case 7:
			display();
			break;
			case 8:
			 exit(0);
			 break;
			default:
			 printf("Invalid Choice\n");
			 break;
		  }
		}while(1);
	 return 0;	
}
