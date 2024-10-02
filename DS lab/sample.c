#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node *next;
}*top=NULL,*newnode,*temp;
char a[50],b[50],p;
int i,j;

void push(char x){
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(top==NULL){
		top=newnode;
		top->next=NULL;
	}
	else{
		newnode->next=top;
		top=newnode;
	}
}

void pop(){
  	p=top->data;
  	b[j]=p;
	top=top->next;
	j++;
}

void main(){
	printf("Enter the string:");
    gets(a);
    int count=0,flag=0;
    for(i=0;a[i]!='\0';i++){
    	push(a[i]);
	}
	j=0;
	while(top!=NULL){
		pop();
	}
	printf("\nReversed string\n");
	puts(b);
	for(i=0;a[i]!='\0';i++){
		if(a[i]!=b[i]){
			printf("Not palindrome");
			flag=1;
			break;
		}
    }
		if(flag==0){
			printf("It is palindrome");
		}
}

