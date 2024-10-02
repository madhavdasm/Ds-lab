#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head=NULL,*temp;

void create(){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("enter data:");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL){
head=newnode;
temp=newnode;}
else{
temp->next=newnode;
temp=newnode;
}
}

void display(){
if(head==NULL)
printf("\nNo list!!\n");
else{
temp=head;
while(temp!=NULL){
printf("%d|",temp->data);
temp=temp->next;
}
}
}

void insertatbeg(){
if(head==NULL)
printf("\nNo list!!\n");
else{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("enter data:");
scanf("%d",&newnode->data);
newnode->next=head;
head=newnode;
}
}

void insertatend(){
if(head==NULL)
printf("\nNo list!!\n");
else{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("enter data:");
scanf("%d",&newnode->data);
temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=newnode;
newnode->next=NULL;
}
}

void insertatsp(){
if(head==NULL)
printf("\nNo list!!\n");
else{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
int key;
printf("enter data to be entered:");
scanf("%d",&newnode->data);
newnode->next=NULL;
printf("enter data after which node to be inserted:");
scanf("%d",&key);
temp=head;
while(temp->data!=key&&temp->next!=NULL){
temp=temp->next;
}
if(temp->data==key){
newnode->next=temp->next;
temp->next=newnode;
}
else{
printf("No such node!!\n");
}
}
}

void delatbeg(){
if(head==NULL)
printf("\nNo list!!\n");
else{
temp=head;
head=head->next;
free(temp);
}
}

void delatend(){
if(head==NULL)
printf("\nNo list!!\n");
else{
struct node *prev;
temp=head;
while(temp->next!=NULL){
prev=temp;
temp=temp->next;
}
prev->next=NULL;
free(temp);
}
}

void delatsp(){
if(head==NULL)
printf("\nNo list!!\n");
else{
int key;
struct node *prev;
printf("enter data after which node to be deleted:");
scanf("%d",&key);
temp=head;
while(temp->data!=key&&temp->next!=NULL){
prev=temp;
temp=temp->next;
}
if(temp->data==key){
prev=temp;
temp=temp->next;
prev->next=temp->next;
free(temp);
}
else{
printf("No such node!!\n");
}
}
}




void main(){
int ch;
do{
printf("\n1.CREATE A NODE\n2.INSERT AT BEGINNING\n3.INSERT AT END\n4.INSERT AT SPECIFIC POSITION\n5.DELETION FROM BEGINNING\n6.DELETION FROM END\n7.DELETION FROM A SPECIFIC POSITION\n8.DISPLAY\n9.EXIT\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:
   create();
   break;
case 2:
   insertatbeg();
   break;
case 3:
   insertatend();
   break;
case 4:
   insertatsp();
   break;
case 5:
   delatbeg();
   break;
case 6:
   delatend();
   break;
case 7:
   delatsp();
   break;
case 8:
   display();
   break;
case 9:
   printf("\nEND OF PROGRAM!!!\n");
   break;
default:
   printf("\nInvalid choice\n");
  }
  }while(ch!=9);
  }
