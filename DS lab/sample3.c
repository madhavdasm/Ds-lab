#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
}*head1=NULL,*head2=NULL,*temp1,*temp2;

struct node* insertion(){
	int ch=1;
	struct node *temp,*newnode,*head=NULL;
    while(ch){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter value:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
		temp=newnode;
	}
	else{
		temp->next=newnode;
		newnode->prev=temp;
		temp=temp->next;
	}
	printf("Do you want to continue(0/1)");
	scanf("%d",&ch);
	}
	return head;
}

void merge(){
	temp1=head1;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=head2;
	head2->prev=temp1;
}

void display(struct node *head){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d|",temp->data);
		temp=temp->next;
	}
}

void sort(struct node *head){
    struct node *temp=head,*t;
    while(temp->next!=NULL){
    	t=head;
    while(t->next!=NULL){
    	if(t->data>t->next->data){
    		int x=t->data;
    		t->data=t->next->data;
    		t->next->data=x;
		}
		t=t->next;
	}
	temp=temp->next;
	}
}

void reverse(){
	struct node *temp=head1;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(temp!=NULL){
		printf("%d|",temp->data);
		temp=temp->prev;
	}
}
    
    

void main(){
	printf("Enter first list..\n");
	head1 = insertion();
	printf("Enter second list..\n");
	head2=insertion(head2);
	printf("First list is..\n");
	display(head1);
	printf("\nSecond list is..\n");
	display(head2);
	sort(head1);
	printf("\nSorted First list is..\n ");
	display(head1);
	sort(head2);
	printf("\nSorted second list is..\n");
	display(head2);
	merge();
	printf("\nmerged list is..\n");
	display(head1);
	printf("\nSorted Merged list is..\n");
	sort(head1);
	display(head1);
	printf("\nReversed List Is....\n");
	reverse();
}
