#include<stdio.h>
int n,alloc[10][10],max[10][10],rem[10][10],available[10][10],i,j,a,b,c=0,k,state,safe[10],r,finish[10],flag,y,available2[10][10],request[10],safe2[10];
int check(int x){
int count;
for(a=0;a<n;a++){
count=0;
for(b=0;b<r;b++){
if(rem[a][b]<=available[x][b]&&finish[a]==-1){
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

int check2(int x){
int count;
for(a=0;a<n;a++){
count=0;
for(b=0;b<r;b++){
if(rem[a][b]<=available2[x][b]&&finish[a]==-1){
count++;
}
if(count==r){
safe2[c]=a+1;
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

void req(){
printf("Enter the process to be requested:");
int p;
c=0;
scanf("%d",&p);
for(i=0;i<10;i++){
finish[i]=-1;
}
for(j=0;j<r;j++){
printf("Enter %d request of process%d:",j+1,p);
scanf("%d",&request[j]);
}
    for(j=0;j<r;j++){
    if(request[j]>rem[p-1][j]||request[j]>available2[0][j]){
    printf("\n Request cannot be granted!!");
    return;
}
}
for(j=0;j<r;j++){
rem[p-1][j]-=request[j];
available2[0][j]-=request[j];
alloc[p-1][j]+=request[j];
}
      y=check2(0);
          flag=0;
     for(i=1;i<=n;i++){
 for(j=0;j<r;j++){
       if(y==-1){
       flag=1;
       printf("\nDEADLOCK!!");
       break;
   }
   else{
   available2[i][j]=available2[i-1][j]+alloc[y][j];
       }
          }
  y=check2(i);
     if(flag==1){
 break;
     }
  }
  printf("\n|PROCESS| |ALLOCATION MATRIX| |MAX NEED MATRIX| |AVAILABLE MATRIX| |REMAINING NEED MATRIX|\n");
  printf("............................................................................................\n");
  for(i=0;i<n;i++){
 printf("|P%d\t|",i+1);
 for(j=0;j<r;j++){
printf("%d ",alloc[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",max[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",available2[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",rem[i][j]);
}
printf("|");
printf("\n");
}
printf(".............................................................................................\n");
if(flag==0){
printf("\nSYSTEM IS SAFE\n");
printf("\nThe safe sequence is...\n");
printf("<");
for(i=0;i<n;i++){
printf("P%d,",safe2[i]);
}
printf(">\n");
   }
else{
printf("SYSTEM IS NOT SAFE\n");
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
printf("Enter %d max need of process%d:",j+1,i+1);
scanf("%d",&max[i][j]);
  }
}
for(i=0;i<n;i++){
for(j=0;j<r;j++){
rem[i][j]=max[i][j]-alloc[i][j];
}
}  
for(j=0;j<r;j++){
 printf("Enter the %d element of available matrix:",j+1);
 scanf("%d",&available[0][j]);
 available2[0][j]=available[0][j];
    }
    y=check(0);
    flag=0;
for(i=1;i<=n;i++){
for(j=0;j<r;j++){
     if(y==-1){
      flag=1;
      printf("\nDEADLOCK!!");
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
printf("\n|PROCESS| |ALLOCATION MATRIX| |MAX NEED MATRIX| |AVAILABLE MATRIX| |REMAINING NEED MATRIX|\n");
printf("..............................................................................\n");
for(i=0;i<n;i++){
printf("|P%d\t|",i+1);
for(j=0;j<r;j++){
printf("%d ",alloc[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",max[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",available[i][j]);
}
printf("|");
for(j=0;j<r;j++){
printf("%d ",rem[i][j]);
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
printf("\nResource request needed?(1 or 0):");
int ch;
scanf("%d",&ch);
if(ch==1){
req();
}
}
