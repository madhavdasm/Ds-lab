#include <stdio.h>
struct process{
    int pid,at,bt,ct,tat,wt,rt;
}p[10],temp;
int n,i,j,k; 
int ct=0,count=0;
float ttat=0.0,twt=0.0;
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

void   main(){
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
    }
    startsort();
    while(count!=n){
        if(ct<p[count].at){
            a[ct]=0;
            ct++;
        }
        else{
            a[ct]=p[count].pid;
            ct+=p[count].bt;
            p[count].ct=ct;
            p[count].tat=p[count].ct-p[count].at;
            ttat=ttat+p[count].tat;
            p[count].wt=p[count].tat-p[count].bt;
            twt=twt+p[count].wt;
            count++;
        }
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    for(i=0;i<ct;i++){
        if(a[i]==0)//for idle time
            printf("||");
        else if(a[i]==-1)//for same process
            printf(" ");
        else        //new process
            printf("|P%d",a[i]);
    }
    printf("|\n");
    for(i=0;i<ct;i++){
        if((i==0 && a[i]==0 ) || (i!=0 && a[i]==0 && a[i-1]!=0))//first idle time or idle time after a process
            printf(" %d ",i);
        else if(i!=0 && a[i]==-1)
            printf(" ");
        else
            printf("%d ",i);
    }
    printf("%d\n",ct);
    printf("Average turnaround time=%f\n",ttat/n);
	printf("Average waiting time=%f",twt/n);
}

