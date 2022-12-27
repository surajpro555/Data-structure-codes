 //stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int data;
};
struct node *top=NULL;
void push(int val)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
   if(top==NULL)
   printf("Stack is Empty\n");
   else
   {
   	 struct node *temp=top;
   	 top=top->next;
   	 free(temp);
   }	
}
int isEmpty()
{
	if(top==NULL)
	return 1;
	return 0;
}
int peek()
{
	if(isEmpty())
	return -1;
	return top->data;	
}
int size(struct node* start)
{
	if(start==NULL)
	return 0;
	return size(start->next)+1;
}
int isFull()
{
   struct node *newnode=(struct node*)malloc(sizeof(struct node));	
   if(newnode==NULL)
   return 1;
   return 0;
}
/*
void display()
{
	if(isEmpty())
	printf("Stack is Empty\n");
	else
	{
		printf("Element of stack:");
		struct node *temp=top;
		while(temp!=NULL)
		{
			printf("%4d",temp->data);
			temp=temp->next;
		}
	}
}
*/
void display(struct node *start)
{
	if(start==NULL)
	 return;
	printf("%4d",start->data);
	display(start->next); 
}
int main()
{
	int val,choice;
	printf("Choose your option:\n");
	printf("1.PUSH\n2.POP\n3.ISEMPTY\n4.ISFULL\n5.PEEK\n6.SIZE\n7.DISPLAY\n8.EXIT\n");
	do
	{   printf("\n--------------------------\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter a inserting element:");
				scanf("%d",&val);
				push(val);
				display(top);
				break;
			case 2:
			     pop();
			    break;
			case 3:
			   if(isEmpty())
			   printf("Stack is Empty\n");
			   else
			   printf("Stack is not empty\n");
			   break;	
			case 4:
			   if(isFull())
			   printf("Stack is overflow\n");
			   else
			   printf("Stack is underflow\n");
			   break;
			case 5:
			   if(peek()==-1)
			    printf("Stack is empty\n");	
			   else
				printf("Peek element:%d",peek());	
				break; 
			case 6:
			    printf("No of element in stack:%d\n",size(top));
				break;
			case 7:
			     display(top);	
				 break;
			case 8:
			   exit(0);
			   break;
			default:
			 printf("INVALID CHOICE\n");
			 break; 
		  }
		}while(1);
	return 0;
}
