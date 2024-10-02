#include<stdio.h>
#define MAX 10
int n,item,prio,i,j,front=-1,rear=-1,order;

struct Priorityqueue{
	int e;
	int p;
}q[MAX],temp;

void ascending_sort(){
	for(i=front+1;i<=rear;i++){
		for(j=front;j<=rear-i;j++){
			if(q[j].p>q[j+1].p){
				temp = q[j];
				q[j]=q[j+1];
				q[j+1] = temp;
			}
		}
	}
}
void descending_sort(){
	for(i=front+1;i<=rear;i++){
		for(j=front;j<=rear-i;j++){
			if(q[j].p<q[j+1].p){
				temp = q[j];
				q[j]=q[j+1];
				q[j+1] = temp;
			}
		}
	}
}
void enqueue(){
	if(rear==n-1){
		printf("Queue overflow..\n");
	}
	else{
		if((rear==-1) && (front==-1)){
			front = 0;
		}
		rear = rear+1;
		printf("Enter the element:");
		scanf("%d",&item);
		printf("Enter the priority value:");
		scanf("%d",&prio);
		q[rear].e=item;
		q[rear].p=prio;printf("FRONT: %d , REAR: %d \n",front,rear);
	}
}
void dequeue(){
	if(front==-1){
		printf("Queue underflow..\n");
	}
	else{
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else{
			front=front+1;
		}
		printf("FRONT: %d , REAR :%d\n ",front,rear);
	}
}
void display(){
	for(i=0;i<front;i++){
		printf(" |");
	}
	for(i=front;i<=rear&&front!=-1;i++){
		printf("%d|",q[i].e);
	}
	for(i=rear+1;i<n;i++){
		printf(" |");
	}
}
int main(){
	int opt;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("1)Ascending\n2)Descending\nChoose the order:");
	scanf("%d",&order);
	printf("\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit");
	do{
		printf("\nChoose your operation:");
		scanf("%d",&opt);
		if(opt==1){
			enqueue();
			if(order==1){
				ascending_sort();
			}
			else if(order==2){
				descending_sort();
			}
			display();
			printf("\n");
		}
		else if(opt==2){
			dequeue();
			display();
			printf("\n");
		}
		else if(opt==3){
			display();
			printf("\n");
		}
		else if(opt!=4){
			printf("\ninvalid input..");
		}
	}while(opt!=4);
}
