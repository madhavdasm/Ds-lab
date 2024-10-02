
#include <stdio.h>
#include <stdlib.h>
struct block{
int id;
int size;
int wastage;
}b[10];
struct process{
int id;
int size;
struct block b;
}p[10];
int bn,pn,max=0;
void firstfit(){
for(int i=0;i<pn;i++){
for(int j=0;j<bn;j++){
if(p[i].size<=b[j].size && b[j].wastage==-1){
p[i].b.id=b[j].id;
p[i].b.size=b[j].size;
p[i].b.wastage=b[j].wastage=b[j].size-p[i].size;
break;
}
}
}
printf("\nFIRST FIT\n");
}
void bestfit(){
int high,id;
for(int i=0;i<pn;i++){
high=max;
id=-1;
for(int j=0;j<bn;j++){
if(p[i].size<=b[j].size && high>=b[j].size && b[j].wastage==-1){
high=b[j].size;
id=j;
}
}
if(id!=-1){
p[i].b.id=b[id].id;
p[i].b.size=b[id].size;
p[i].b.wastage=b[id].wastage=b[id].size-p[i].size;
}
}
printf("\nBEST FIT\n");
}
void worstfit(){
int high,id;
for(int i=0;i<pn;i++){
high=b[0].size;
id=-1;
for(int j=0;j<bn;j++){
if(b[j].size>=p[i].size && high<=b[j].size && b[j].wastage==-1){
high=b[j].size;
id=j;
}
}
if(id!=-1){
p[i].b.id=b[id].id;
p[i].b.size=b[id].size;
p[i].b.wastage=b[id].wastage=b[id].size-p[i].size;
}
}
printf("\nWORST FIT\n");
}
void display_reset(){
printf("Process\t\tSize\t\tBlock\t\tSize\t\tWastage\n");
for(int i=0;i<pn;i++){
printf("P%d\t\t%d\t\t",p[i].id,p[i].size);
if(p[i].b.wastage!=-1)
printf("B%d\t\t%d\t\t%d\n",p[i].b.id,p[i].b.size,p[i].b.wastage);
else
printf("-\t\t-\t\t-\n");
p[i].b.id=p[i].b.size=p[i].b.wastage=-1;
}
for(int i=0;i<bn;i++){
b[i].wastage=-1;
}
}
void main(){
printf("Enter number of blocks : ");
scanf("%d",&bn);
for(int i=0;i<bn;i++){
b[i].id=i+1;
printf("Enter Block%d size : ",(i+1));
scanf("%d",&b[i].size);
b[i].wastage=-1;
if(max<b[i].size)
max=b[i].size;
}
printf("Enter number of process : ");
scanf("%d",&pn);
for(int i=0;i<pn;i++){
p[i].id=i+1;
printf("Enter Process%d size : ",(i+1));
scanf("%d",&p[i].size);
p[i].b.wastage=-1;
}
firstfit();
display_reset();
bestfit();
display_reset();
worstfit();
display_reset();
}
