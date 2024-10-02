#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL,*newnode,*temp;

void insertion(){
	int ch=1;
	while(ch){
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter value:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
	}
	printf("Do you want to continue(0/1)");
	scanf("%d",&ch);
}
}

void even(){
	temp=head;
	printf("Even numbers are..\n");
	while(temp!=NULL){
		if(temp->data%2==0){
			printf("%d\n",temp->data);
		}
		temp=temp->next;
		
	}
}

void max(){
	temp=head;
	int x=0;
	while(temp!=NULL){
		if(temp->data>x){
			x=temp->data;
		}
		temp=temp->next;
	}
	printf("\nmaximum element is %d",x);
}

void main(){
	insertion();
	even();
	max();
}

