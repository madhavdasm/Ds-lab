#include<stdio.h>
int n,alloc[10][10],req[10][10],available[10][10],i,j,a,b,c=0,k,safe[10],r,finish[10],flag,y;
int check(int x){
int count;
for(a=0;a<n;a++){
count=0;
for(b=0;b<r;b++){
if(req[a][b]<=available[x][b]&&finish[a]==-1){
count++;
}
if(count==r){
safe[c]=a+1;
finish[a]=0;
c++;
return a;
}
}
  }
  if(count!=r){
    return -1;
  }
}

void main(){
for(i=0;i<10;i++){
finish[i]=-1;
}
printf("Enter no of processes:");
scanf("%d",&n);
printf("Enter no of resources:");
scanf("%d",&r);
for(i=0;i<n;i++){
for(j=0;j<r;j++){
printf("Enter %d allocation of process%d:",j+1,i+1);
scanf("%d",&alloc[i][j]);
}
}
for(i=0;i<n;i++){
for(j=0;j<r;j++){
printf("Enter %d request of process%d:",j+1,i+1);
scanf("%d",&req[i][j]);
  }
}  
for(j=0;j<r;j++){
 printf("Enter the %d element of available matrix:",j+1);
 scanf("%d",&available[0][j]);
    }
y=check(0);
flag=0;
for(i=1;i<=n;i++){
for(j=0;j<r;j++){
     if(y==-1){
      flag=1;
      printf("\nDEADLOCK DETECTED!!");
      break;
 }
else{
available[i][j]=available[i-1][j]+alloc[y][j];
}
   }
y=check(i);
if(flag==1){
break;
}
}
printf("\n|PROCESS| |ALLOCATION MATRIX| |REQUEST MATRIX| |AVAILABLE MATRIX|\n");
printf("..............................................................................\n");
for(i=0;i<n;i++){
printf("|P%d\t|",i+1);
for(j=0;j<r;j++){
printf("%d ",alloc[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",req[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",available[i][j]);
}
printf("|");
printf("\n");
}
printf("...............................................................................\n");
if(flag==0){
printf("\nSYSTEM IS SAFE\n");
printf("\nThe safe sequence is...\n");
printf("<");
for(i=0;i<n;i++){
printf("P%d,",safe[i]);
}
printf(">\n");
   }
else{
printf("SYSTEM IS NOT SAFE\n");
}
}
