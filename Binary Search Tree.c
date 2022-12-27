 //BST
#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *left;
  struct node *right;
  int data;	
};
void preorder(struct node *root)
{
	if(root==NULL)
	return;
	printf("|%d|-->",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("|%d|-->",root->data);
	inorder(root->right);
}
void postorder(struct node *root)
{
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("|%d|-->",root->data);
}
struct node *insert(struct node *root,int val)
{
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=val;
   newnode->left=NULL;
   newnode->right=NULL;
   if(root==NULL)
    root=newnode;
   else
   {
   	 struct node *pnode,*temp;
   	 temp=root;
   	 while(temp!=NULL)
   	  {
   	  	pnode=temp;
   	  	if(val<temp->data)
   	  	temp=temp->left;
   	  	else
   	  	temp=temp->right;
	  }
	  if(val<pnode->data)
	  pnode->left=newnode;
	  else
	  pnode->right=newnode;
   }
   return root;	  
}

struct node *deletenode(struct node *root,int val)
{
	   if(root==NULL)
	    root=root;
	   else if(val<root->data)
		root->left=deletenode(root->left,val);
	   else if(val>root->data)
		root->right=deletenode(root->right,val);
	   else
		{
			if(root->left==NULL)
			{
			  struct node *temp=root->right;
			  free(root);
			  return temp;
			}
			else if(root->right=NULL)
			{
				struct node *temp=root->left;
				free(root);
				return temp;
			}
			else
			{
				struct node *min=root->right;
				while(min->left!=NULL)
				  min=min->left;
				root->data=min->data;
				root->right=deletenode(root->right,min->data);
			}
		}
	return root;
}
struct node *search(struct node *root,int val)
{
	if(root==NULL||val==root->data)
	return root;
	else if(val<root->data)
	return search(root->left,val);
	else
	return search(root->right,val);
}
struct node *smallest(struct node *root)
{
	if(root==NULL)
	return root;
	if(root->left==NULL)
	return root;
	return smallest(root->left);
}
struct node *biggest(struct node *root)
{
	if(root==NULL)
	return root;
	if(root->right==NULL)
	return root;
	return biggest(root->right);
}
int countnode(struct node *root)
{
	if(root==NULL)
	return 0;
	return countnode(root->left)+countnode(root->right)+1;
}
int countleaf(struct node *root)
{
	if(root==NULL)
	return 0;
	if(root->left==NULL&&root->right==NULL)
	return 1;
	return countleaf(root->left)+countleaf(root->right);
}
int countinternalnode(struct node *root)
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
	return 0;
	return countinternalnode(root->left)+countinternalnode(root->right)+1;
}
int height(struct node *root)
{
	if(root==NULL)
	return -1;
	int  max=(height(root->left)>height(root->right)?height(root->left):height(root->right));
	return max+1;
}
int main()
{
	int val,ch;
	struct node *root=NULL;
	printf("choose your option:\n");
	printf("1.Insertion\n2.deletion\n3.searching\n4.preorder\n5.Inorder\n6.postorder\n7.smallest\n8.biggest\n9.count node\n10.count leaf node\n11.count internal\n12.height\n13.Exit\n");
	do
	{
	  printf("\n--------------------------------\n");
	  printf("Enter your choice:");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	    case 1:
	    	printf("Enter insert a value:");
	    	scanf("%d",&val);
	    	root=insert(root,val);
	    	preorder(root);
	    	printf("\n");
	    	postorder(root);
	    	printf("\n");
	    	inorder(root);
	    	printf("\n");
	    	break;
	  	case 2:
	  		printf("Enter delete a value:");
	    	scanf("%d",&val);
	  		root=deletenode(root,val);
	    	preorder(root);
	    	postorder(root);
	    	inorder(root);
	    	break;
		case 3:
			printf("Enter a value:");
	    	scanf("%d",&val);
	    	if(search(root,val)!=NULL)
	    	printf("ELement found\n");
	    	else
	    	printf("Element not found\n");
		   break;
		case 4:
			preorder(root);
			printf("\n");
		   break;
		case 5:
		    inorder(root);
		    printf("\n");
			break;
		case 6:
		   postorder(root);	
		   printf("\n");
		   break;
		case 7:
			if(smallest(root)!=NULL)
		   printf("Smallest element:%d\n",smallest(root)->data);
		   else
		   printf("No element is present\n");
		   break;
		case 8:
			if(biggest(root)!=NULL)
		   printf("Biggest element:%d\n",biggest(root)->data);
		   else
		   printf("No element is present\n");
		   break;
		case 9:
		   printf("Total no. of node:%d\n",countnode(root));
		   break; 
		case 10:
		   printf("Total no. of leaf node:%d\n",countleaf(root));  
		   break;
		case 11:
		   printf("Total no. of internal node:%d\n",countinternalnode(root));  
		   break;
		case 12:
		   printf("Height of tree:%d\n",height(root));
		   break;
		case 13:
		  exit(0);
		  break;
		default:
		 printf("Invalid choice\n");
		 break;                       		
	  }	
	}while(1);
	return 0;
}
