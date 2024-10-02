#include<stdio.h>
int a[10],size,rear=0,front=0,item;

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

void insertion1(){
	if(front==0&&rear==0){
		front=1;
		rear=1;
		printf("Enter element to insert:");
		scanf("%d",&item);
		a[front]=item;
		display();
	}
	else if(front==1){
			front=size;
			printf("Enter element to insert:");
		    scanf("%d",&item);
			a[front]=item;
			display();
		}
	else if(front==(rear%size)+1){
			printf("Overflow!!");
		}
    else{
    	front=front-1;
        printf("Enter value to be inserted:");
		scanf("%d",&item);
		a[front]=item;
		display();
	}
}

void insertion2(){
		if(front==0&&rear==0){
			front=1;
			rear=1;
			printf("Enter value to be inserted:");
		    scanf("%d",&item);
	     	a[rear]=item;
		    display();
			
		}
		else if(front==(rear%size)+1){
		printf("overflow!!");
		}
		else{
			rear=(rear%size)+1;
			printf("Enter value to be inserted:");
		    scanf("%d",&item);
		    a[rear]=item;
		    display();
		}
	}

void deletion1(){
	if(front==0&&rear==0){
		printf("\nQUEUE IS EMPTY!!\n");
	}
	else if(front==rear){
		    printf("deleted item is %d",a[rear]);
			front=0;
			rear=0;
		}
	else if(rear==1){
		    printf("deleted item is %d",a[rear]);
			rear=size;;
		}
	else{
		 printf("deleted item is %d",a[rear]);
		 rear=rear-1;
	}
		display();
	}

void deletion2(){
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



void main(){
	int ch;
	printf("Enter size of queue:");
	scanf("%d",&size);
	do{
		printf("\n1.INPUT RESTRICTED\n2.OUTPUT RESTRICTED\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice..:"); 
		scanf("%d",&ch);
		switch(ch)
		{  
		int ch1;
			case 1:
				do{
				printf("\n1.INSERTION AT REAR\n2.DELETION AT FRONT\n3.DELETION AT REAR\n4.DISPLAY\n5.EXIT\n");
				printf("Enter your choice...");
				scanf("%d",&ch1);
				if(ch1==1){
					insertion2();
					
				}
				else if(ch1==2){
					deletion2();
				}
				else if(ch1==3){
					deletion1();
					
				}
				else if(ch1==4){
					display();
					}
				else if(ch1==5){
					printf("BYE!!");
					
				}
				else{
					printf("\ninvalid choice!!\n");
				}}while(ch1!=5);
				break;
			case 2:
				do{
				printf("\n1.INSERTION AT REAR\n2.INSERTION AT FRONT\n3.DELETION AT FRONT\n4.DISPLAY\n5.EXIT\n");
				printf("Enter your choice...");
				scanf("%d",&ch1);
				if(ch1==1){
					insertion2();
					
				}
				else if(ch1==2){
					insertion1();
				}
				else if(ch1==3){
					deletion2();
					
				}
				else if(ch1==4){
					display();
					}
				else if(ch1==5){
					printf("BYE!!");
					
				}
				else{
					printf("\ninvalid choice!!\n");
				}}while(ch1!=5);
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
