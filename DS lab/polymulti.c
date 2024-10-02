#include<stdio.h>
#include<stdlib.h>
struct node{
int coeff,pow;
struct node*next;
};
struct node*head1,*temp1,*head2,*temp2,*temp3,*head3,*pdtnode,*prev,*nxt;

void check(){
	if(head3==NULL){
		head3=pdtnode;
		temp3=pdtnode;
	}
	else{
		temp3->next=pdtnode;
		temp3=pdtnode;
	}
	temp3->next=NULL;
}
void polymulti(){
	temp1=head1;
	temp2=head2;
	head3=NULL;
	while(temp1!=NULL){
		while(temp2!=NULL){
		pdtnode=(struct node*)malloc(sizeof(struct node));
		pdtnode->coeff=temp1->coeff*temp2->coeff;
		pdtnode->pow=temp1->pow+temp2->pow;
		check();
		temp2=temp2->next;
		}
	temp2=head2;
	temp1=temp1->next;
	}
	temp3=head3;
    while(temp3!=NULL){
    	prev=temp3;
    	nxt=temp3->next;
    	while(nxt!=NULL){
    	if(temp3->pow==nxt->pow){
    		temp3->coeff=temp3->coeff+nxt->coeff;
    		prev->next=nxt->next;
    		free(nxt);
    		nxt=prev->next;
		}
		else{
			prev=nxt;
			nxt=nxt->next;
		}
	}
	temp3=temp3->next;
}
}

struct node * create(){
	struct node *head=NULL,*temp;
	struct node *newnode;
	int ch=1;
	while(ch){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter coeffient:");
		scanf("%d",&newnode->coeff);
		printf("enter power:");
		scanf("%d",&newnode->pow);
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
			temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		printf("press 0 to discontinue and 1 to continue:");
		scanf("%d",&ch);
	}
	return head;
}

void display(struct node *head,struct node *temp){
	temp=head;
	while(temp!=NULL){
		printf("%dx^%d",temp->coeff,temp->pow);
		temp=temp->next;
        if(temp!=NULL&&temp->coeff>=0){
			printf("+");
		}
	}
}

void main()
{
 printf("Enter first polynomial\n");
 head1=create();
 printf("\nfirst polynomial is\n");
 display(head1,temp1);
 printf("\nEnter second polynomial\n");
 head2=create();
 printf("\nsecond polynomial is\n");
 display(head2,temp2);
 polymulti();
 printf("\nPdt of polynomials is..\n");
 display(head3,temp3);	
}
