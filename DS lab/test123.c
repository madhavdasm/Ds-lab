#include<stdio.h>
#include<stdlib.h>
int target,opt,order;
struct BST{
	int data;
	struct BST *rlink , *llink;
}*newnode,*temp,*parent,*succ,*root=NULL;

void create_node(){
	newnode = (struct BST*)malloc(sizeof(struct BST));
	printf("\nEnter the value of data:");
	scanf("%d",&newnode->data);
	newnode->llink = NULL;
	newnode->rlink = NULL;
}

void searching(){
	printf("\nEnter the element to Search:");
	scanf("%d",&target);
	if(root == NULL){
		printf("There is no such a tree!!!!!");
	}
	else{
		temp=root;
		while(temp!=NULL){
			if(target>temp->data){
				temp = temp->rlink;
			}
			else if(target<temp->data){
				temp = temp->llink;
			}
			else{
				printf("\n%d is found!!!!!",target);
				return;
			}
		}
		printf("\n%d is Not found !!",target);
		return;
	}
}

void inorder_display(struct BST *node){
	if(node==NULL){
		return;
	}
	else{
		inorder_display(node->llink);
		printf("%d |",node->data);
		inorder_display(node->rlink);
	}
}
void postorder_display(struct BST *node){
    if(node==NULL){
		return;
	}
	else{
		postorder_display(node->llink);
		postorder_display(node->rlink);
		printf("%d |",node->data);
	}
}
void preorder_display(struct BST *node){
	if(node==NULL){
		return;
	}
	else{
		printf("%d |",node->data);
		preorder_display(node->llink);
		preorder_display(node->rlink);
	}
}
void display(){
printf("\n1)Inorder\n2)Preorder\n3)Postorder\nchoose:");
			scanf("%d",&order);
			if(order==1){
			   inorder_display(root);
			    printf("\n");	
			}
			else if(order==2){
			   preorder_display(root);
			   printf("\n");
			}
			else if(order==3){
			   postorder_display(root);
			   printf("\n");
			}
			else{
			 printf("\nInvalid input!!\n");
			}

}
void Insertion(){
	create_node();
	if(root == NULL){
		root = newnode;
		printf("\nInsertion successfull!!!!!");
	}
	else{
		temp=root;
		while(temp!=NULL){
			if(newnode->data>temp->data){
				if(temp->rlink==NULL){
					temp->rlink = newnode;
					break;
				}
				else{
					temp=temp->rlink;
				}
			}
			else if(newnode->data<temp->data){
				if(temp->llink==NULL){
					temp->llink = newnode;
					break;
				}
				else{
					temp = temp->llink;
				}
			}
			else{
				printf("Element is already exist!!");
				return;
			}
		}
		printf("\nInsertion successfull!!!!!");
	}
}
void Deletion(){
	printf("\nEnter the element to be deleted:");
	scanf("%d",&target);
	temp=root;
	int flag=0;
	while(temp!=NULL && flag==0){
		if(target>temp->data){
				parent = temp;
				temp = temp->rlink;
		}
		else if(target<temp->data){
			parent=temp;
			temp = temp->llink;
		}
		else{
			flag=1;
		}
	}
	if(flag==0){
		printf("\nNO such node exist!!");
	}
	else{
		if(temp->llink == NULL && temp->rlink == NULL){  	//with 0 child
			if(parent->rlink == temp){
				parent->rlink = NULL;
			}
			else{
				parent->llink = NULL;
			}
			free(temp);
		}
		else if(temp->llink != NULL && temp->rlink != NULL){   //with 2 child
			succ = temp->llink;
			while(succ->rlink!=NULL){
				parent = succ;
				succ = succ->rlink;
			}
			temp->data = succ->data;
			parent->rlink = NULL;
			free(succ);
		}
		else{												  //with 1 child
			if(temp->data>parent->data){
				if(temp->llink!=NULL){
					parent->rlink = temp->llink;
					temp->llink = NULL;
					free(temp);
				}
				else if(temp->rlink!=NULL){
					parent->rlink = temp->rlink;
					temp->rlink = NULL;
					free(temp);
				}
			}
			else{
				if(temp->llink!=NULL){
					parent->llink = temp->llink;
					temp->llink = NULL;
					free(temp);
				}
				else if(temp->rlink!=NULL){
					parent->llink = temp->rlink;
					temp->rlink = NULL;
					free(temp);
				}
			}
		}
	}
	
}
int main(){
	printf("\n1)Insertion\n2)Deletion\n3)Searching\n4)Traversal\n5)Exit");
	do{
		printf("\nChoose the operation:");
		scanf("%d",&opt);
		if(opt==1){
			Insertion();
			printf("\n");
			inorder_display(root);
			printf("\n");
		}
		else if(opt==2){
			Deletion();
			inorder_display(root);
			printf("\n");
		}
		else if(opt==3){
			searching();
			inorder_display(root);
			printf("\n");
		}
		else if(opt==4){
			if(root==NULL){
				printf("Tree is empty!!");
			}
			else{
			  display();
			}
			
		}
		else if(opt!=5){
			printf("Invalid input!!");
		}
	}while(opt!=5);
	
}
