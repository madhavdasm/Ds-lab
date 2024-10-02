#include<stdio.h>
int visited[100],ad[100][100];
int n;
void bfs(int start)
{
	int queue[100],i,k,front=-1,rear=-1;
	for(k=0;k<n;k++)
	{
		visited[k]=0;
	}
	queue[++rear]=start;
	front++;
	visited[start]=1;
	while(rear>=front)
	{
		start=queue[front++];
		printf("%d ",start);
		
		for(i=0;i<n;i++)
		{
			if(ad[start][i]==1 && visited[i]==0)
			{
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}
}


void dfs(int start)
{
	int stack[100],top=-1,k,i;
	for(k=0;k<n;k++)
	{
		visited[k]=0;
	}
	stack[++top]=start;
	visited[start]=1;
	while(top!=-1)
	{
		start=stack[top--]; 
		printf("%d ",start);
		
		for(i=0;i<n;i++)
		{
			if(ad[start][i]==1 && visited[i]==0)
			{
				stack[++top]=i;
				visited[i]=1;
				printf("%d",i);
				start=i;
			}
		}
	}
	
}
 void main()
{	int i,j,s;
	printf("Enter the no.of vertices");
	scanf("%d",&n);
	printf("Enter the adjacency matrix");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		scanf("%d",&ad[i][j]);
	}
	}
	printf("Enter the source vertex");
	scanf("%d",&s);
	printf("bfs");
	bfs(s);
	printf("dfs");
	dfs(s);
}














