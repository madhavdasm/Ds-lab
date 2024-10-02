#include<stdio.h>
#include<string.h>
struct page{
	char pg;
	int fut;
}p[30];

struct frame{
	char pg;
	int r;
}f[30];
char str[50];
int n,i,j,flag,fault=0,pos,k,len,a,maxfut[30];

int optimal(int index){
	int count=0,max=0,min=100;
	for(j=0;j<n;j++){
		int got=0;
		for(k=index;k<len;k++){
			if(f[j].pg==p[k].pg){
				maxfut[j]=p[k].fut;
				got=1;
				break;
			}
		}
		if(got==0){
				maxfut[j]=-1;
				count+=1;
				pos=j;
		}
   }
   if(count==1){
   	 return pos;
   }
   if(count==0){
     for(j=0;j<n;j++){
   	    if(max<maxfut[j]){
   	  	   max=maxfut[j];
   	  	   pos=j;
		 }
    }   
       	return pos;
  }
  else{
  	  for(j=0;j<n;j++){
   	    if(min>f[j].r){
   	  	   min=f[j].r;
   	  	   pos=j;
		 }
    }
  	return pos;
  }   
}

void insert(char x,int rec){
		f[i].pg=x;
		f[i].r=rec;
}

void main(){
	int hit=0;
	printf("Enter the reference string:");
	fgets(str,50, stdin);
	printf("Enter no of frames:");
	scanf("%d",&n);
	len=strlen(str)-1;
	for(i=0;i<len;i++){
		p[i].pg=str[i];
		p[i].fut=i+1;
	}
	for(i=0;i<strlen(str)-1;i++){
		flag=0;
		printf("Element is %c\n\n",str[i]);
		for(j=0;j<n;j++){
           if(str[i]==f[j].pg){
				flag=1;
				printf("This is a hit\n\n");
				hit++;
		   }
	   }
	if(i<n&&flag==0){
		insert(str[i],i+1);
		fault++;
		printf("This is a fault!!\n\n");
	}
	if(i>=n&&flag==0){
		int m=optimal(i);
		fault++;
		f[m].pg=str[i];
		f[m].r=i+1;
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


