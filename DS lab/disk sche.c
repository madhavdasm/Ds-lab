#include<stdio.h>
int a[30],i,j,n,cp,d,seek,size;

int diff(int a,int b){
	if(a>b){
		return a-b;
	}
	else{
		return b-a;
	}
}

void sort(){
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j+1]<a[j]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void fcfs(){
	seek=0;
	printf("Enter no of requests:");
	scanf("%d",&n);
	printf("Enter the track requests:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the current head position:");
	scanf("%d",&cp);
	d=diff(cp,a[0]);
	printf("\nSearching sequence is..\n");
	printf("\n%d->%d",cp,a[0]);
	seek=seek+d;
	for(i=1;i<n;i++){
		printf("->%d",a[i]);
		d=diff(a[i-1],a[i]);
		seek=seek+d;
	}
	printf("\n\nTotal seek time:%d\n",seek);
}

void scan(){
	int start;
	printf("Enter no of requests:");
	scanf("%d",&n);
	printf("Enter the track requests:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
    }
	int done[n+2];
	for(i=0;i<n+3;i++){
		done[i]=-1;
	}
	printf("Enter the current head position:");
	scanf("%d",&cp);
	a[n]=cp;
	a[n+1]=size;
	n=n+2;
	sort();
	for(i=0;i<n;i++){
		if(a[i]==cp){
			start=i;
		}
	}
	printf("\nSearching sequence is..\n");
	for(i=start;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){
			printf("->");
		}
		done[i]=0;
	}
	for(i=n-1;i>=0;i--){
		if(done[i]==-1){
			printf("->%d",a[i]);
		}
	}
	seek=(size-cp)+(size-a[0]);
	printf("\n\nTotal seek time:%d\n",seek);
}

void cscan(){
	int start;
	printf("Enter no of requests:");
	scanf("%d",&n);
	printf("Enter the track requests:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int done[n+3];
	for(i=0;i<n+3;i++){
		done[i]=-1;
	}
	printf("Enter the current head position:");
	scanf("%d",&cp);
	a[n]=cp;
	a[n+1]=0;
	a[n+2]=size;
	n+=3;
	sort();
	for(i=0;i<n;i++){
		if(a[i]==cp){
			start=i;
		}
	}
	printf("\nSearching sequence is..\n");
	for(i=start;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){
			printf("->");
		}
		done[i]=0;
	}
	for(i=0;i<start;i++){
		if(done[i]==-1){
			printf("->%d",a[i]);
		}
	}
	seek=(a[n-1]-cp)+(a[n-1]-a[0])+(a[start-1]-a[0]);
	printf("\n\nTotal seek time:%d\n",seek);
}

void look(){
	int start;
	printf("Enter no of requests:");
	scanf("%d",&n);
	printf("Enter the track requests:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int done[n+1];
	for(i=0;i<n+1;i++){
		done[i]=-1;
	}
	printf("Enter the current head position:");
	scanf("%d",&cp);
	a[n]=cp;
	n+=1;
	sort();
	for(i=0;i<n;i++){
		if(a[i]==cp){
			start=i;
		}
	}
	printf("\nSearching sequence is..\n");
	for(i=start;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){
			printf("->");
		}
		done[i]=0;
	}
	for(i=n-1;i>=0;i--){
		if(done[i]==-1){
			printf("->%d",a[i]);
		}
	}
	seek=(a[n-1]-cp)+(a[n-1]-a[0]); 
	printf("\n\nTotal seek time:%d\n",seek);
}

void clook(){
	int start;
	printf("Enter no of requests:");
	scanf("%d",&n);
	printf("Enter the track requests:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int done[n+1];
	for(i=0;i<n+1;i++){
		done[i]=-1;
	}
	printf("Enter the current head position:");
	scanf("%d",&cp);
	a[n]=cp;
	n+=1;
	sort();
	for(i=0;i<n;i++){
		if(a[i]==cp){
			start=i;
		}
	}
	printf("\nSearching sequence is..\n");
	for(i=start;i<n-1;i++){
		printf("%d",a[i]);
		if(i!=n-2){
			printf("->");
		}
		done[i]=0;
	}
	for(i=1;i<start;i++){
		if(done[i]==-1){
			printf("->%d",a[i]);
		}
	}
	seek=(a[n-1]-cp)+(a[n-1]-a[0])+(a[start-1]-a[0]); 
	printf("\n\nTotal seek time:%d\n",seek);
}

void main(){
	int ch;
	printf("Enter the size of disk:");
	scanf("%d",&size);
	size-=1;
	do{
		printf("\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.LOOK\n5.C-LOOK\n6.EXIT\nEnter choice:");
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
		    	printf("\nTerminating!!");
		    	break;
		    default:
		    	printf("\nInvalid choice\n");
	}}while(ch!=6);
}
