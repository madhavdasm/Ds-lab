#include<stdio.h>  
int a[10],size,rear=0,front=0;
void enqueue(){
	if(front==(rear%size)+1){
		printf("\nQUEUE IS FULL!!\n");
	}
	else{
		if(front==0){
			front=1;
			rear=1;
		}
		else{
			rear=(rear%size)+1;
		}
		int x;
        printf("Enter value to be inserted:");
		scanf("%d",&x);
		a[rear]=x;
		display();
	}
}

void dequeue(){
	if(front==0){
		printf("\nQUEUE IS EMPTY!!\n");
	}
	else{
		printf("\ndeleted value is %d\n",a[front]);
		if(front==rear){
			front=0;
			rear=0;
		}
		else{
			front=(front%size)+1;
		}
		display();
	}
}

void display(){
	int i;
	if(front==0){
		printf("\nEMPTY QUEUE!!\n");
	}
	else{
	 printf("\nCurrent stack\n");
     for(i=front;i!=rear;i=(i%size)+1)
	 {
	 printf("%d|",a[i]);
}
    printf("%d",a[rear]);
}
}

void main(){
	int ch;
	printf("Enter size of queue:");
	scanf("%d",&size);
	do{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice..:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nEnd of program!!");
				break;
			default:
				printf("\nInvalid choice\n");
		}
	}while(ch!=4);
}
