#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int data;
};
struct node *head=NULL;
void create(int n)
{  
    int val;
    struct node *temp=head;
    while(n--)
    {
    printf("Enter a value:");
	scanf("%d",&val);	
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;	
    if(head==NULL)
     head=newnode;
    else
	 temp->next=newnode;
	 
	temp=newnode; 
   }
}
void insertatbegin(int val)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->next=NULL;	
   if(head==NULL)
   {
   	 head=newnode;
   }
   else
   {
      newnode->next=head;
	  head=newnode;   	
	}	
}
void insertatend(int val)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->next=NULL;	
   if(head==NULL)
   {
   	 head=newnode;
   }
   else
   {
   	 struct node *temp=head;
   	 while(temp->next!=NULL)
   	  temp=temp->next;
   	  
      temp->next=newnode;  	
	}	
}
void insertbeforenode(int val,int bn)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->next=NULL;	
   if(head==NULL)
   {
   	 head=newnode;
   }
   else if(head->data==bn)
   {
    insertatbegin(val);
   }
   else
   {
   	 struct node *temp1=head;
   	 struct node *temp2=NULL;
   	 while(temp1->data!=bn)
   	 {
   	   temp2=temp1;	
   	  temp1=temp1->next;
     }
      temp2->next=newnode; 
	  newnode->next=temp1; 	
	}	
}
void deleteatbegin()
{
	if(head==NULL)
	printf("Linked list is empty\n");
	else
	 {
	 struct node *temp=head;
	 head=head->next;
	 free(temp); 	
    }
}
void deleteatend()
{
	if(head==NULL)
	printf("Linked is Empty\n");
	else if(head->next==NULL)
	deleteatbegin();
	else
	{
		struct node *temp=head;
		while(temp->next->next!=NULL)
		 temp=temp->next;
		 free(temp->next);
		 temp->next=NULL;
	}
}
void deletebeforenode(int val)
{
	 if(head==NULL)
   {
   	 printf("Linked list is empty\n");
   }
   else if(head->data==val)
   {
      deleteatbegin();
   }
   else
   {
   	 struct node *temp1=head;
   	 struct node *temp2=NULL;
   	 while(temp1->data!=val)
   	 {
   	   temp2=temp1;	
   	  temp1=temp1->next;
     }
      temp2->next=temp1->next; 
	  free(temp1); 	
	}	
}
void reverse(struct node *start)
{
	if(start==NULL)
	{
		printf("NULL");
		return;
	}
	reverse(start->next);
	printf("<---%d",start->data);
}
void sort()
{
  struct node *temp1,*temp2;
  for(temp1=head;temp1!=NULL;temp1=temp1->next)
  {
	for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
	{
		if(temp1->data>temp2->data)
		{
			int t;
			t=temp1->data;
			temp1->data=temp2->data;
			temp2->data=t;
		}
	}
  }
}
int size(struct node *start)
{ 
    if(start==NULL)
      return 0;
	return size(start->next)+1;
}
int search(int val)
{
	if(head==NULL)
	return 0;
	else
	{
	  struct node *temp=head;
	  while(temp!=NULL)
	  {
	   if(temp->data==val)
	    return 1;
		temp=temp->next;	
      }
	  return 0; 	
	}
}
void display()
{
	if(head==NULL)
	{
		printf("Linked list is Empty\n");
		return;
	}
	else
	{
	  struct node *temp=head;
	  while(temp!=NULL)
	  {
	  	 printf("%d--->",temp->data);
	  	 temp=temp->next;
	  }	
	  printf("NULL\n");
	}
}
int main()
{
	int val,ch,bn,n;
	printf("Choose your option:\n");
	printf("0.Create list\n1.INSERTION AT BEGIN\n2.INSERT AT END\n3.Insert BEFORE A NODE\n4.DELETE AT BEGIN\n5.DELETE AT END\n6.DELETE BEFORE A NODE\n");
	printf("7.DISPLAY\n8.REVERSE\n9.SORT\n10.SIZE\n11.SEARCH\n12.Exit\n");
	do
	{
		printf("\n----------------------------\n");
	  	printf("Enter your option:");
	  	scanf("%d",&ch);
	  	switch(ch)
	  	{
	  	  case 0:
			 printf("Enter size of list:");
			 scanf("%d",&n);
			 create(n);
			 break;	
	  	  case 1:
			printf("Enter inserting element:");
			scanf("%d",&val);
			insertatbegin(val);
			display();
			break;
		  case 2:
			printf("Enter inserting element:");
			scanf("%d",&val);
			insertatend(val);
			display();
			break;	
		  case 3:
		    printf("Enter inserting element and before node:");
			scanf("%d%d",&val,&bn);
			insertbeforenode(val,bn);
			display();
			break;
		  case 4:
		    deleteatbegin();
		    display();
			break;
		  case 5:
		     deleteatend();
		     display();
			 break;
	      case 6:
	         	printf("Enter node before deletion to occured:");
		     	scanf("%d",&val);
		       deletebeforenode(val);
		       display();
			   break;
		  case 7:
		     display();
			 break;
 		 case 8:
		     reverse(head);
			 break;
	 	 case 9:
		    sort();
		    display();
		    break;
		 case 10:
		    printf("Count of nodes in Linked list:%d",size(head));
		    break;
		 case 11:
		    printf("Enter searching node:");
		   	scanf("%d",&val);
		    if(search(val))
		    printf("Element is present\n");
		    else
		    printf("Element is not present\n");
			break;		    	 	   		 				
		 case 12:
		    exit(0);
			break;		
		}
	}while(1);
	return 0;
}
