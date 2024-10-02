#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL,*temp,*newnode,*prev,*current,*temp1,*temp2;

void insertion(){
	int ch=1;
	while(ch){
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter value:");
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
	printf("do you want to continue(0/1)");
	scanf("%d",&ch);
}
}

void display(){
	temp=head;
	while(temp!=NULL){
		printf("%d|",temp->data);
		temp=temp->next;
	}
}

void duplicate(){
	temp1=head;
	while(temp1->next!=NULL){
		temp2=temp1->next;
		while(temp2!=NULL){
			if(temp1->data==temp2->data){
				prev->next=temp2->next;
				free(temp2);
				temp2=prev;
			}
			if(temp2!=NULL){
				prev=temp2;
			temp2=temp2->next;
			}
		}
		temp1=temp1->next;
	}
}

void reverse(){
	temp=head;
	current=temp->next;
	while(current!=NULL){
		prev=temp;
		temp=current;
		current=temp->next;
		temp->next=prev;
	}
	head->next=NULL;
	head=temp;
}

void main(){
	printf("Start entering...\n");
	insertion();
	printf("\nOg list is..\n");
	display();
	//printf("\nReversed list is..\n");
	//reverse();
	printf("\nWithout duplicate\n");
	duplicate();
	display();
}
