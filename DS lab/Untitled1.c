#include <stdio.h>
 int a[30],i,j,k,temp,seek,d,n,cp,size,start,done[30],min,cur,low,high;
 
 int diff(int a,int b){
     if(a>b)
        return a-b;
    else
        return b-a;
 }
 
 void sort(){
     for(i=0;i<n-1;i++){
         for(j=0;j<n-i-1;j++){
             if(a[j+1]<a[j]){
                 temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
             }
         }
     }
 }
 
 void fcfs(){
     seek=0;
     printf("enter no of request :");
     scanf("%d",&n);
     printf("enter track request :");
     for(i=0;i<n;i++){
         scanf("%d",&a[i]);
     }
     printf("enter current head pos :");
     scanf("%d",&cp);
     d=diff(cp,a[0]);
     printf("sequence");
     printf("\n%d -> %d",cp,a[0]);
     seek=seek+d;
     for(i=1;i<n;i++){
         printf("-> %d",a[i]);
         d=diff(a[i-1],a[i]);
         seek=seek+d;
     }
     printf("total seek time = %d",seek);
 }
 
 void sstf(){
     seek=0;
     printf("enter no of request :");
     scanf("%d",&n);
     printf("enter track request :");
     for(i=0;i<n;i++){
         scanf("%d",&a[i]);
     }
     printf("enter current head pos :");
     scanf("%d",&cp);
     sort();
     printf("sequence\n");
     printf("%d",cp);
     low=0;
     while(a[low+1]<cp)
        low++;
     high=low+1;
     for(i=0;i<n;i++){
        if(diff(cp,a[low])<diff(cp,a[high]) && low>=0){
            seek=seek+diff(cp,a[low]);
            cp=a[low];
            low-=1;
        }
        else{
            seek=seek+diff(cp,a[high]);
            cp=a[high];
            high+=1;
        }
         printf("-> %d",cp);
     }
     printf("\ntotal seek time = %d",seek);
 }
 
 void scan(){
     seek=0;
     printf("enter no of request :");
     scanf("%d",&n);
     printf("enter track request :");
     for(i=0;i<n;i++){
         scanf("%d",&a[i]);
     }
     done[n+3];
     for(i=0;i<n+3;i++){
         done[i]=-1;
     }
     printf("enter current head pos :");
     scanf("%d",&cp);
     a[n]=cp;
     a[n+1]=0;
     a[n+2]=size;
     n=n+3;
     sort();
     for(i=0;i<n;i++){
         if(a[i]==cp){
             start=i;
         }
     }
     printf("sequence");
     for(i=start;i<n;i++){
         printf("%d",a[i]);
         if(i!=n-1){
             printf("->");
         }
         done[i]=0;
     }
     for(i=n-1;i>0;i--){
         if(done[i]==-1){
             printf("-> %d",a[i]);
         }
     }
     seek=(size-cp)+(size-0);
     printf("total seek time = %d",seek);
 }
 
 void cscan(){
     seek=0;
     printf("enter no of request :");
     scanf("%d",&n);
     printf("enter track request :");
     for(i=0;i<n;i++){
         scanf("%d",&a[i]);
     }
     done[n+3];
     for(i=0;i<n+3;i++){
         done[i]=-1;
     }
     printf("enter current head pos :");
     scanf("%d",&cp);
     a[n]=cp;
     a[n+1]=0;
     a[n+2]=size;
     n=n+3;
     sort();
     for(i=0;i<n;i++){
         if(a[i]==cp){
             start=i;
         }
     }
     printf("sequence");
     for(i=start;i<n;i++){
         printf("%d",a[i]);
         if(i!=n-1){
             printf("->");
         }
         done[i]=0;
     }
     for(i=0;i<start;i++){
         if(done[i]==-1){
             printf("-> %d",a[i]);
         }
     }
     seek=(a[n-1]-cp)+(a[n-1]-0)+(a[start-1]-0);
     printf("total seek time = %d",seek);
 }
 
  void look(){
     seek=0;
     printf("enter no of request :");
     scanf("%d",&n);
     printf("enter track request :");
     for(i=0;i<n;i++){
         scanf("%d",&a[i]);
     }
     done[n+1];
     for(i=0;i<n+3;i++){
         done[i]=-1;
     }
     printf("enter current head pos :");
     scanf("%d",&cp);
     a[n]=cp;
     n=n+1;
     sort();
     for(i=0;i<n;i++){
         if(a[i]==cp){
             start=i;
         }
     }
     printf("sequence");
     for(i=start;i<n;i++){
         printf("%d",a[i]);
         if(i!=n-1){
             printf("->");
         }
         done[i]=0;
     }
     for(i=n-1;i>0;i--){
         if(done[i]==-1){
             printf("-> %d",a[i]);
         }
     }
     seek=(a[n-1]-cp)+(a[n-1]-a[0]);
     printf("total seek time = %d",seek);
 }
 
 void clook(){
     seek=0;
     printf("enter no of request :");
     scanf("%d",&n);
     printf("enter track request :");
     for(i=0;i<n;i++){
         scanf("%d",&a[i]);
     }
     done[n+1];
     for(i=0;i<n+3;i++){
         done[i]=-1;
     }
     printf("enter current head pos :");
     scanf("%d",&cp);
     a[n]=cp;
     n=n+1;
     sort();
     for(i=0;i<n;i++){
         if(a[i]==cp){
             start=i;
         }
     }
     printf("sequence");
     for(i=start;i<n;i++){
         printf("%d",a[i]);
         if(i!=n-1){
             printf("->");
         }
         done[i]=0;
     }
     for(i=0;i<start-1;i++){
         if(done[i]==-1){
             printf("-> %d",a[i]);
         }
     }
     seek=(a[n-1]-cp)+(a[n-1]-a[0])+(a[start-1]-a[0]);
     printf("total seek time = %d",seek);
 }
 
 void main(){
 int ch;
 printf("enter disk size:");
 scanf("%d",&size);
 size=size-1;
 do{
  printf("\n1.fcfs\n2.scan\n3.c-scan\n4.look\n5.clook\n6.sstf\n7.exit\nenter choice:");
  scanf("%d",&ch);
  switch(ch){
   case 1:
    fcfs();
          break;
      case 2:
       scan();
       break;
      case 3:
       cscan();
       break;
       case 4:
       look();
       break;
       case 5:
       clook();
       break;
       case 6:
       sstf();
       break;
      case 7:
       printf("\nterminating!!");
       break;
      default:
       printf("\ninvalid choice\n");
 }
 }while(ch!=7);
}
