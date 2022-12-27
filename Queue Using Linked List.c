 //Queue using Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *next;
  int data;	
};
struct node *rear=NULL;
struct node *front=NULL;
void enqueue(int val)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(rear==NULL)
	{
       rear=newnode;
       front=newnode;
    }
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	if(rear==NULL)
	printf("Queue is Empty\n");
	else if(rear==front)
	{
		rear=NULL;
		front=NULL;
	}
	else
	{
	  struct node *temp=front;
	  front=front->next;
	  free(temp);	
	}
}
int isEmpty()
{
	if(rear==NULL)
	return 1;
	return 0;
}
int isFull()
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL)
  return 1;
  return 0;	
}
int getFront()
{
	if(isEmpty())
	return -1;
	return front->data;
}
int getRear()
{
	if(isEmpty())
	return -1;
	return rear->data;
}
void display()
{
	if(isEmpty())
	printf("Queue is Empty\n");
	else
	{
	  struct node *temp=front;
	  while(temp!=NULL)
	  {
	  	printf("%3d",temp->data);
	  	temp=temp->next;
	  }
	}
}
int size(struct node *start)
{
	if(start==NULL)
	return 0;
	return size(start->next)+1;
}
int main()
{
	int val,ch;
	printf("Choose your option:\n");
	printf("1.enqueue\n2.dequeue\n3.isEmpty\n4.isFull\n5.getFront\n6.getRear\n7.size\n8.display\n9.EXIT");
	do
	{
	  printf("\n---------------------\n");	
	  printf("Enter your choice:");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	  	case 1:
	  		printf("\nEnter a value:");
	  		scanf("%d",&val);
	  		enqueue(val);
	  		display();
	  		break;
	  	case 2:
		   dequeue(); 
		   display();
		   break;
		case 3:
		   if(isEmpty())
		   printf("Queue is Empty\n");
		   else
		   printf("Queue is Not Empty\n");
		   break;
		case 4:
		    if(isFull())
		     printf("Queue is Overflow\n");
		   else
		   printf("Queue is Underflow\n");
		   break;
		case 5:
		    if(getFront()==-1)
			printf("Queue is Empty\n");
		   else
		   printf("Front element of Queue:%d",getFront());
		   break;
		case 6:
			if(getRear()==-1)
			printf("Queue is Empty\n");
		   else
		   printf("Rear element of Queue:%d",getRear());
		   break;
		case 7:
		   printf("No. of Element in Queue:%d",size(front));
		   break;
	    case 8:
		   display();
		   break;
		case 9:
		  exit(0);
		  break;
		default:
		  printf("Invalid choice\n");
		  break;     	         
	  }
	}while(1);
	return 0;
}
