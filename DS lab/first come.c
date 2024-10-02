#include<stdio.h>
struct process{
	int at,bt,ct,tat,wt,pid;
}p[100],temp;
int n,i,j,a[100];

void sort(){
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j+1].at<p[j].at){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				
			}
		}
	}
}


void main(){
	for(i=0;i<100;i++){
		a[i]=-1;
	}
	printf("enter no of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p[i].pid=i+1;
		printf("Enter the arrival time of process%d:",i+1);
		scanf("%d",&p[i].at);
		printf("Enter the burst time of process%d:",i+1);
		scanf("%d",&p[i].bt);
	}
	sort();
	p[0].ct=p[0].bt;
	p[0].tat=p[0].ct-p[0].at;
	p[0].wt=p[0].tat-p[0].bt;
	a[0]=1;
	int count=0;
	for(i=1;i<=n;i++){
		if(p[i-1].ct<p[i].at){
			a[i]=0;
			count++;
			int it=p[i].at-p[i-1].ct;
			p[i].ct=p[i-1].ct+p[i].bt+it;
	        p[i].tat=p[i].ct-p[i].at;
		    p[i].wt=p[i].tat-p[i].bt;
		}
		else{
		a[i]=1;
		p[i].ct=p[i-1].ct+p[i].bt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
}
	printf("PROCESS\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++){
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("...........................................................................\n");
    printf("\nGANTT CHART\n");
    int jt=0;
    for(i=0;i<n+count;i++){
    if(a[i]==1){
    printf("|P%d\t",p[jt].pid);
    jt++;
    }
    if(a[i]==0){
    printf("|idle\t");
  }
  }
  jt=0;
  printf("|");
  printf("\n");
  printf("%d\t",p[0].at);
  for(i=0;i<=n+count;i++){
    if(a[i]==1){
    printf("%d\t",p[jt].ct);
    jt++;
    }
    if(a[i]==0){
     printf("%d\t",p[jt+1].at);
  }
  }
}
