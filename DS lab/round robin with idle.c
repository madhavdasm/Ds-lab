#include <stdio.h>
struct process{
    int pid,at,bt,ct,tat,wt,dbt,c;
}p[10],temp;
int n,i,j,k;
int t,count=0,ts;
int A[100];
int rq[30];
int front=0,rear=0;
float ttat=0,twt=0;
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
    for(i=0;i<ts;i++){//execution of the process till time slice
        if(p[a].dbt!=0){
            A[t]=p[a].pid;
            t++;
            p[a].dbt--;
        }
    }
    if(p[a].dbt==0){//process completed nd inserting the req values
        p[a].ct=t;
        count++;
        p[a].tat=p[a].ct-p[a].at;
        p[a].wt=p[a].tat-p[a].bt;
        ttat+=p[a].tat;
        twt+=p[a].wt;
    }
}
void check(){//checking if new/unchecked process is there,if yes add it to ready queue
    for(i=0;i<n;i++){
        if(p[i].ct==0 && p[i].c==0 && p[i].at<=t){
            rq[rear]=p[i].pid;
            rear++;
            p[i].c=1;
        }
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
    printf("Enter the time slice : ");
    scanf("%d",&ts);
    startsort();
    t=p[0].at;
    for(i=0;i<t;i++){//inserts 0 to array A if idle time before first process
        A[i]=0;
    }
    check();
    do{
        for(j=0;j<n;j++){
            if(p[j].pid==rq[front] && front<rear){//execution part ,reduces the dbt
                reduce(j);
                front++;
                break;
            }
        }
        check();
        if(p[j].dbt!=0 && j!=n){//if process is yet to complete the execution
            rq[rear]=p[j].pid;
            rear++;
        }
        if(front==rear && count!=n){//for idle time computation
            A[t]=0;
            t++;
        }
    }while(count<n);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    for(i=0;i<t;i++){
        if(A[i]>0 && (i==0 || (i!=0 && A[i]!=A[i-1])))
            printf("|P%d",A[i]);
        if(A[i]==0)
            printf("//");
        else if(A[i]==A[i+1])
            printf("  ");
    }
    printf("|\n");
    for(i=0;i<t;i++){
        if(A[i]>0 && (i==0 || (i!=0 && A[i]!=A[i-1])))
            printf("%d ",i);
        if((i==0 && A[i]==0) || (A[i]==0 && A[i-1]!=0))
            printf("%d ",i);
        else if(A[i]==A[i+1])
            printf("  ");    
    }  
    printf("%d\nAverage Turn-around time=%.2f\nAverage Waiting time=%.2f",t,(ttat)/n,(twt)/n);
}
