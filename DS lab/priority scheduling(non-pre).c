#include <stdio.h>
struct process{
int pid,priority,at,bt,ct,tat,wt,rt;
}p[10],temp;
int n,i,j,k;
int ct,count=1;
void startsort(){
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(p[j].at>p[j+1].at){
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(p[j].at==p[j+1].at && p[j].priority>p[j+1].priority){
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
}
void burstsort(int start, int end){
int i;
        int low=start;
        for(i=start;i<end;i++){
        if(p[low].priority>p[i].priority)
        low=i;
        }
    if(low!=start){
        temp=p[start];
        p[start]=p[low];
        p[low]=temp;
        }
}
void main(){
float ttat=0,twt=0;
printf("MAX PRIORITY = 1\n");
int a[100];
printf("Enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<100;i++){
    a[i]=-1;
}
for(i=0;i<n;i++){
p[i].pid=(i+1);
printf("Enter the arrival time of %d : ",(i+1));
scanf("%d",&p[i].at);
printf("Enter the burst time of %d : ",(i+1));
scanf("%d",&p[i].bt);
printf("Enter the priority of %d : ",(i+1));
scanf("%d",&p[i].priority);
}
startsort();
ct=p[0].at+p[0].bt;
p[0].ct=ct;
a[p[0].at]=p[0].pid;
p[0].tat=p[0].ct-p[0].at;
p[0].wt=p[0].tat-p[0].bt;
ttat+=p[0].tat;
twt+=p[0].wt;
while(count!=n){
if(ct<p[count].at){
        a[ct]=0;
        ct++;
    }  
  else{
      k=count;
      while(p[k].at<=ct && k<n){
  k++;
      }
      if(k!=count+1)
  burstsort(count,k);
      a[ct]=p[count].pid;
      ct+=p[count].bt;
      p[count].ct=ct;
      p[count].tat=p[count].ct-p[count].at;
      p[count].wt=p[count].tat-p[count].bt;
      ttat+=p[count].tat;
twt+=p[count].wt;
      count++;
     
  }      
}
printf("PID\tAT\tBT\tCT\tTAT\tWT\tPRIORITY\n");
for(i=0;i<n;i++){
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].priority);
}
for(i=0;i<ct;i++){
  if(a[i]==0)
      printf("///");
  else if(a[i]==-1)
      printf("   ");
  else
      printf("|P%d ",a[i]);
}
printf("|\n");
for(i=0;i<ct;i++){
  if((i==0 && a[i]==0 ) || (i!=0 && a[i]==0 && a[i-1]!=0))
      printf("%d  ",i);
  else if(i!=0 && a[i]==-1)
      printf("   ");
  else
      printf("%d   ",i);
}
printf("%d\n",ct);
printf("Average turn-around time = %.2f\nAverage waiting time = %.2f",(ttat/5),(twt/5));
}

