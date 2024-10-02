#include<stdio.h>
int ad[100][100],visited[100],n;
void dfs(int start){
	int stack[100],top=-1,i;
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	stack[++top]=start;
	visited[start]=1;
	printf("%d",start);
	while(top!=-1){
		start=stack[top--];
		for(i=0;i<n;i++){
		while(ad[start][i]==1&&visited[i]==0){
			stack[++top]=i;
			visited[i]=1;
			printf("%d",i);
			start=i;
		}
		
	}
}
	
}

void bfs(int start){
	int queue[100],rear=-1,front=-1,i;
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	queue[++rear]=start;
	front++;
	visited[start]=1;
	while(rear>=front){
		start=queue[front++];
		printf("%d",start);
		for(i=0;i<n;i++){
		while(ad[start][i]==1&&visited[i]==0){
			queue[++rear]=i;
			visited[i]=1;
		}
		
	}
}
	
}

void main(){
	int i,j,s;
	printf("Enter size:");
	scanf("%d",&n);
	printf("enter adjucency matrix:");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&ad[i][j]);
		}
	}
	printf("Enter the source vertex:");
	scanf("%d",&s);
	printf("\nbfs\n");
	bfs(s);
	printf("\ndfs\n");
	dfs(s);
	
	
}



