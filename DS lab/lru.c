#include<stdio.h>
#include<string.h>
struct frame{
	char pg;
	int r;
}f[30];
char str[50];
int n,top=-1,i,j,flag,k,fault=0,min,pos;

int least(){
	min=100;
	for(j=0;j<n;j++){
		if(f[j].r<min){
			min=f[j].r;
			pos=j;
		}
}
	return pos;
}

void insert(char x,int p){
		top++;
		f[top].pg=x;
		f[top].r=p+1;
}

void main(){
	int hit=0;
	printf("Enter the reference string:");
	fgets(str,50, stdin);
	printf("Enter no of frames:");
	scanf("%d",&n);
	for(i=0;i<strlen(str)-1;i++){
		flag=0;
		printf("Element is %c\n\n",str[i]);
		for(j=0;j<n;j++){
           if(str[i]==f[j].pg){
				f[j].r=i+1;
				flag=1;
				printf("This is a hit\n\n");
				hit++;
		   }
	   }
	if(i<n&&flag==0){
		insert(str[i],i);
		fault++;
		printf("This is a fault!!\n\n");
	}
	if(i>=n&&flag==0){
		int m=least();
		fault++;
		f[m].pg=str[i];
		f[m].r=i+1;
		printf("This is a fault!!\n\n");
	}
	for(k=0;k<n;k++){
		printf("\t|%c|\n",f[k].pg,f[k].r);
	}  
  	printf("...............\n");
  }	
    printf("................\n");
  	printf("Final Frame    |\n");
  	printf("...............|\n");
	for(k=0;k<n;k++){
		printf("\t|%c|\n",f[k].pg);
	}  
  	printf("...............\n");
    printf("\nNo of page faults:%d",fault);
    printf("\nNo of hits:%d",hit);
    int deno=hit+fault;
    printf("\nHit ratio:%d/%d",hit,deno);
}


