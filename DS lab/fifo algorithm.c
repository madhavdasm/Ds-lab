#include<stdio.h>
#include<string.h>
char str[50],frame[10];
int n,top=-1,i,j,flag,k,fault=0,hit=0;
void insert(int x){
	if(top==n-1){
		top=0;
		frame[top]=x;
	}
	else{
		top++;
		frame[top]=x;
	}
}

void main(){
	printf("Enter the reference string:");
	fgets(str,50, stdin);
	printf("Enter no of frames:");
	scanf("%d",&n);
	for(i=0;i<strlen(str)-1;i++){
		flag=0;
		for(j=0;j<n;j++){
           if(str[i]==frame[j]){
				flag=1;
				hit++;
				printf("This is a hit!!\n\n");
		   }
	   }
	if(flag==1){
		continue;
	}
	else{
		insert(str[i]);
		printf("This is a fault!!\n\n");
		fault++;
	}
	for(k=0;k<n;k++){
	printf("|%c|\n",frame[k]);
	}  
  	printf("...............\n");
  }	
    printf("................\n");
  	printf("Final Frame    |\n");
  	printf("...............|\n");
	for(k=0;k<n;k++){
		printf("\t|%c|\n",frame[k]);
	}  
  	printf("...............\n");
    printf("\nNo of page faults:%d",fault);
    printf("\nNo of hits:%d",hit);
    int deno=hit+fault;
    printf("\nHit ratio:%d/%d",hit,deno);
}


