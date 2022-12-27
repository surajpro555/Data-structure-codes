#include<stdio.h>
#include<stdlib.h>
#define max 10
int a[max];
int hashing(int key)
{
	return key%max;
}
void linear(int key)
{
    int hashcode,k;
    for(k=0;k<max;k++)
    {
	hashcode=hashing(hashing(key)+k);
	 if(a[hashcode]==-1)
	  { 
		a[hashcode]=key;
		break;
	  } 
    }
    printf("Numebr of collsion:%d\n",k);
}
void quadratic(int key)
{
	int hashcode,k;
    for(k=0;k<max;k++)
    {
	hashcode=hashing(hashing(key)+k*k);
	 if(a[hashcode]==-1)
	  { 
		a[hashcode]=key;
		break;
	  } 
    }
    printf("Numebr of collsion:%d",k);
}
void display()
{
	int i;
	printf("\n------------------------------------------------------------\n");
	for(i=0;i<max;i++)
	printf("|%d|",a[i]);
	printf("\n------------------------------------------------------------\n");
}
void initilise()
{ int i;
	for(i=0;i<max;i++)
	a[i]=-1;
}
int main()
{
	int key,ch,n,i;
	do
	{
	initilise();
	printf("Enter the number of Element:");
	scanf("%d",&n);	
	printf("Choose your option:\n");
	printf("1.LINEAR PROBING\n2.QUADRATIC PROBING\n3.EXIT\n");
	printf("Choose your option:");
	scanf("%d",&ch);
	switch(ch)
	  {
			case 1:
			for(i=0;i<n;i++)
			{
			  printf("Enter the element:");
			  scanf("%d",&key);
			  linear(key);
			  display();	
			}	
			break;
		   case 2:
			for(i=0;i<n;i++)
			{
			  printf("Enter the element:");
			  scanf("%d",&key);
			  quadratic(key);
			  display();	
			}	
			break;
		case 3:
		  exit(0);
		  break;
		default:
		  printf("Invalid choice\n");
		  break;  		
		}
     }while(1);
	return 0;
}
