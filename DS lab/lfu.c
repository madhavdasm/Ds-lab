#include<stdio.h>
#include<string.h>
struct frame{
	char pg;
	int r;
	int freq;
}f[30];
char str[50];
int n,top=-1,i,j,flag,k,fault=0,pos,recent=0;

int least(){
	int minf=100,mincount=0,a[10],minr=100;
	for(j=0;j<n;j++){
		if(f[j].freq<minf){
			minf=f[j].freq;
		}
}
	for(j=0;j<n;j++){
		if(f[j].freq==minf){
			mincount+=1;
			pos=j;
		}
}
    if(mincount==1){
    		return pos;
	}
	else if(mincount>1){
	  for(j=0;j<n;j++){
		if(f[j].freq==minf&&f[j].r<minr){
			minr=f[j].r;
			pos=j;

		}

}
	return pos;
	}
    
}

void insert(char x,int p){
		top++;
		f[top].pg=x;
		f[top].r=p;
		f[top].freq=1;
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
				f[j].freq+=1;;
				flag=1;
				printf("This is a hit\n\n");
				hit++;
		   }
	   }
	if(i<n&&flag==0){
		recent+=1;
		insert(str[i],recent);
		fault++;
		printf("This is a fault!!\n\n");
	}
	if(i>=n&&flag==0){
		recent+=1;
		int m=least();
		fault++;
		f[m].pg=str[i];
		f[m].r=recent;
		f[m].freq=1;
		printf("This is a fault!!\n\n");
	}

	for(k=0;k<n;k++){
		printf("|%c|\n",f[k].pg);
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


