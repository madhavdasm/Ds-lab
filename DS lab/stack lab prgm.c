#include<stdio.h>
struct node{
	char data;
	struct node *next;
}*top=NULL,*newnode;
char a[50],b[50];

void push(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter character:");
	scanf("%c",&newnode->data);
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
	
	top=top->next;
}

void main(){
	printf("Enter the string:");
    char s;
    gets(s);
}
