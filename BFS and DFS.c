#include<stdio.h>
#include<stdlib.h>
int rear=-1;
int front=-1;
int queue[10];
int n;
char a[10];
void bfs(int adj[10][10],int vis[10],int start)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(vis[i]==0&&adj[start][i]==1)
		{
			vis[i]=1;
			printf("%d ",i);
			queue[++rear]=i;
		}
	}
	front++;
	if(front<=rear)
	bfs(adj,vis,queue[front]);
}
void dfs(int adj[10][10],int vis[10],int start)
{
   int i;
   for(i=0;i<n;i++)
   {
   		if(vis[i]==0&&adj[start][i]==1)
		{
			vis[i]=1;
			printf("%d ",i);
			dfs(adj,vis,i);
	    }
	}	
}
void create(int vis[])
{
	int i;
  for(i=0;i<n;i++)
    vis[i]=0;
}
int main()
{
   int adj[10][10],ch,vis[10],i,j,start;
   printf("Enter the nober of vertices:");
   scanf("%d",&n);
   printf("Enter element:");
   for(i=0;i<n;i++)
   {
   	for(j=0;j<n;j++)
   	{
   	  scanf("%d",&adj[i][j]);	
    }
   }
   printf("1.BFS\n2.DFS\n3.Exit\n");
   do
   {
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
     create(vis);
   	printf("Enter starting element index:");
   	scanf("%d",&start);
   	vis[start]=1;
   	queue[++rear]=start;
   	front++;
   	printf("BFS:%c ",a[start]);
   	bfs(adj,vis,start);
   	break;
   	case 2:
   	create(vis);
   	printf("Enter starting element index:");
   	scanf("%d",&start);
   	vis[start]=1;
   	printf("\nDFS:%c",a[start]);
   	dfs(adj,vis,start);
   	break;
   	case 3:
   		exit(0);
   		break;
   	}
   }while(1);
   return 0;
}
