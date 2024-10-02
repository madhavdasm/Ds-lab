#include<stdio.h>
void main(){
	int ch;
	do{
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
		printf("Enter your choice..:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			//	push();
				break;
			case 2:
			//	pop();
				break;
			case 3:
			//	display();
				break;
			case 4:
				printf("End of program!!");
				break;
			default:
				printf("Invalid choice");
		}
	}while(ch!=4);
}
