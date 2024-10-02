#include<stdio.h>
int pivot;

void swap(int a,int b){
	int temp=a;
	a=b;
	b=temp;
}

int partition(int a[],int lb,int ub){
	pivot=a[lb];
	int start=lb;
	int end=ub;
	while(start<end){
		while(a[start]<=pivot){
			start++;
		}
		while(a[end]>pivot){
			end--;
		}
		if(start<end){
			swap(a[start],a[end]);
			
		}
	}
	swap(a[lb],a[end]);
	return end;
}

void quicksort(int a,int lb,int ub){
	if(lb<ub){
		int loc=partition(a,lb,ub);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);
	}
}

void main(){
	int n,i,j;
    printf("Enter size:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nbefore sorting..\n");
	for(i=0;i<n;i++){
		printf("%d|",a[i]);
	}
	quicksort(a,0,n-1);
	printf("\After sorting..\n");
	for(i=0;i<n;i++){
		printf("%d|",a[i]);
	}
		
}
