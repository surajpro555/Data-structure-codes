#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
int isEmpty()
{
	if(top==-1)
	return 1;
	return 0;
}
int isFull()
{
	if(top==max-1)
	return 1;
	return 0;
}
void push(int val)
{
	if(top==max-1)
	{
		printf("Sorry bro you can not add element\n");
		return;
	}
	stack[++top]=val;
}
int pop()
{
	int temp;
	temp=stack[top];
	top--;
	return temp;
}
int peek()
{
	if(top==-1)
	return -1;
	return stack[top];
}
void display()
{
	if(isEmpty())
	{
	  printf("Stack is empty\n");
	}
	else
	{
		int i;
	    for(i=top;i>=0;i--)
		 printf("%3d",stack[i]);	
	}
	printf("\n");
}
int size()
{
	return top+1;
}
int main()
{
	int val,choice;
	printf("please choose your option:\n");
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
				display();
				break;
			case 2:
			    if(!isEmpty())
				printf("Poped element:%d\n",pop());
				else
				printf("Stack is empty\n");	
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
			    printf("No of element in stack:%d\n",size());
				break;
			case 7:
			     display();	
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
