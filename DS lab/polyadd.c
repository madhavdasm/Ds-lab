#include<stdio.h>
#include<stdlib.h>
struct node{
int coeff,pow;
struct node*next;
};
struct node*head1,*temp1,*head2,*temp2,*temp3,*head3,*sumnode;

void check(){
	if(head3==NULL){
		head3=sumnode;
		temp3=sumnode;
	}
	else{
		temp3->next=sumnode;
		temp3=sumnode;
	}
	temp3->next=NULL;
}

void polysum(){
	temp1=head1;
	temp2=head2;
	head3=NULL;
	while(temp1!=NULL&&temp2!=NULL){
		sumnode=(struct node*)malloc(sizeof(struct node));
        if(temp1->pow>temp2->pow){
			sumnode->coeff=temp1->coeff;
			sumnode->pow=temp1->pow;
			check();
			temp1=temp1->next;
		}
		else if(temp1->pow<temp2->pow){
			sumnode->coeff=temp2->coeff;
			sumnode->pow=temp2->pow;
			check();
			temp2=temp2->next;
		}
		else{
			sumnode->coeff=temp1->coeff+temp2->coeff;
			sumnode->pow=temp1->pow;
			check();
			temp2=temp2->next;
			temp1=temp1->next;
		}
	}
	while(temp1!=NULL){
		sumnode=(struct node*)malloc(sizeof(struct node));
        sumnode->coeff=temp1->coeff;
        sumnode->pow=temp1->pow;
        check();
		temp1=temp1->next;
		
	}
	while(temp2!=NULL){
		sumnode=(struct node*)malloc(sizeof(struct node));
		sumnode->coeff=temp2->coeff;
		sumnode->pow=temp2->pow;
		check(); 
		temp2=temp2->next;
		
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
		if(head==NULL]	head=newnode;
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
 polysum();
 printf("\nSum of polynomials is..\n");
 display(head3,temp3);	
}
