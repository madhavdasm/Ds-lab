#include <stdio.h>
struct process{
    int pid,at,bt,ct,tat,wt,dbt,c;
}p[10],temp;
int n,i,j,k;
int t,count=0,ts;
int A[100];
int rq[30];
int front=0,rear=-1,ttat=0,twt=0;
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
}
void reduce(int a){
    for(i=0;i<ts;i++){
        if(p[a].dbt!=0){
            A[t]=p[a].pid;
            t++;
            p[a].dbt--;
        }
    }
    if(p[a].dbt==0){
        p[a].ct=t;
        count++;//tracking the no of processes
        p[a].tat=p[a].ct-p[a].at;
        p[a].wt=p[a].tat-p[a].bt;
        ttat+=p[a].tat;
        twt+=p[a].wt;
    }
}
void main(){
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=(i+1);
        printf("Enter the arrival time of %d : ",(i+1));
        scanf("%d",&p[i].at);
        printf("Enter the burst time of %d : ",(i+1));
        scanf("%d",&p[i].bt);
        p[i].dbt=p[i].bt;
        p[i].c=0;
    }
    printf("Enter the  time slice : ");
    scanf("%d",&ts);
    startsort();
    t=p[0].at;
    for(i=0;i<t;i++){//checking for idle time before first process
        A[i]=0;
    }
    for(i=0;i<n;i++){//inserting all the process that came with first process
        if(p[i].ct==0 && p[i].at<=t){
            rear++;
            rq[rear]=p[i].pid;
            p[i].c=1;
        }
    }
    do{
        for(j=0;j<n;j++){//execution part (reducing the burst time acc to time slice) 
            if(p[j].pid==rq[front]){
                reduce(j);
                front++;
                break;
            }
        }
        for(i=0;i<n;i++){//inserting new process to queue
            if(p[i].ct==0 && p[i].c==0 && p[i].at<=t){
                rear++;
                rq[rear]=p[i].pid;
                p[i].c=1;
            }
        }
        if(p[j].dbt!=0){//inserting the process which has remaining time after the execution 
            rear++;
            rq[rear]=p[j].pid;
        }
    }while(count<n);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    for(i=0;i<t;i++){
        if((i==0 && A[i]>0) || (i!=0 && A[i]!=A[i-1]))
            printf("|P%d",A[i]);
        if(A[i]==A[i+1])
            printf("  ");
        else if(A[i]==0)
            printf("\\");
    }
    printf("|\n");
    for(i=0;i<t;i++){
        if((i==0 && A[i]>0) || (i!=0 && A[i]!=A[i-1]))//new process after a process
            printf("%d  ",i);
        if(A[i]==A[i+1])//same process execution
            printf("  ");
        else if(A[i]==0 && A[i+1]!=0)//new process after an idle time
            printf("%d ",i);
     }
    printf("%d|",t);
}

