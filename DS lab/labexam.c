#include<stdio.h>
struct process{
	int pid,at,bt,tat,wt,priority,ct;
}p[10],temp;
int i,j,n,count=1,t=0,k;
float ttat=0.0,twt=0.0;

void startsort(){
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j].at>p[j+1].at){
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
			}
		}	
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j].at==p[j+1].at&&p[j].priority>p[j+1].priority){
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
			}
		}	
	}
	
}

void priosort(int start,int end){
	int low=start;
	for(i=start;i<end;i++){
		if(p[low].priority>p[i].priority){
			low=i;
		}
	}
	if(low!=start){
		temp=p[start];
		p[start]=p[low];
		p[low]=temp;
	}
}

void main(){
	printf("enter no of processes:");
	scanf("%d",&n);
	int a[50];
	for(i=0;i<50;i++){
		a[i]=-1;
	}
	for(i=0;i<n;i++){
		p[i].pid=i+1;
		printf("Enter AT of process%d:",i+1);
		scanf("%d",&p[i].at);
		printf("Enter BT of process%d:",i+1);
		scanf("%d",&p[i].bt);
		printf("Enter priority of process%d:",i+1);
		scanf("%d",&p[i].priority);
	}
	startsort();
	a[t]=p[0].pid;
	t=p[0].at+p[0].bt;
	p[0].ct=t;
	p[0].tat=p[0].ct-p[0].at;
	ttat=ttat+p[0].tat;
	p[0].wt=p[0].tat-p[0].bt;
	twt=twt+p[0].wt;
	while(count!=n){
		if(p[count].at>t){
			a[t]=0;
			t++;
		}
		else{
			k=count;
			while(p[k].at<=t&&k<n){
				k++;
			}
			if(k!=count+1){
			   priosort(count,k);
		    }
	        a[t]=p[count].pid;
	        t=t+p[count].bt;
			p[count].ct=t;
			p[count].tat=p[count].ct-p[count].at;
			ttat=ttat+p[count].tat;
			p[count].wt=p[count].tat-p[count].bt;
			twt=twt+p[count].wt;
			count++;
		}
	}
	printf("PROCESS\tAT\tBT\tPRIORITY\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].priority,p[i].ct,p[i].tat,p[i].wt);
	}
	printf("\n");
	for(i=0;i<t;i++){
		if(a[i]==0){
			printf("||");
		}
		if(a[i]==-1){
			printf("  ");
		}
		else{
			printf("|P%d",a[i]);
		}
	}
	printf("|\n");
	for(i=0;i<t-1;i++){
		if((i==0&&a[i]==0)||(i!=0&&a[i]==0&&a[i]!=0)){
			printf("%d ",i);
		}
		if(i!=0&&a[i]==-1){
			printf(" ");
		}
		else{
			printf("%d ",i);
		}
	}
	printf("%d\n",t);
	printf("avg TWT=%f\n",ttat/n);
	printf("avg WT=%f",twt/n);

	}
	

