#include<stdio.h>
int a[10],size,top=-1;
void push(){                                     
	if(top==size-1){                                 
		printf("\nSTACK OVERFLOW!!\n");
	}
	else{
		int x;
        printf("Enter value to be inserted:");
		scanf("%d",&x);
		top++;
		a[top]=x;
		display();
	}
}

void pop(){
	if(top==-1){
		printf("\nSTACK UNDERFLOW!!\n");
	}
	else{
		printf("\nPopped value is %d\n",a[top]);     
		top--;
		display();
	}
}

void display(){
	int i;
	if(top==-1){
		printf("\nSTACK IS EMPTY!!\n");
	}
	else{
	 printf("\nCurrent stack is..\n");
     for(i=top;i>=0;i--)
	 printf("%d\n",a[i]);
}
}

void main(){
	int ch;
	printf("Enter size of array:");
	scanf("%d",&size);
	do{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice..:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
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
