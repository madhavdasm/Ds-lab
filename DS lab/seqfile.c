#include <stdio.h>
#include <string.h>
int a[100],b[30],k=0,x,y,start,r;
char name[10];
struct fileTable {
    char name[20];
    int sb, nob;
};

int check(int a[],int b[]){
	for(x=0;x<r;x++){
		for(y=0;y<100;y++){
		     if(b[x]==a[y]){
		     	return 1;
			 }	
		}
	}
	if(x==r){
		return 0;
	}
}

void main() {
    struct fileTable ft[30];
    int i, j, n,count=0;
    char s[20];
    printf("**SEQUENTIAL FILE ALLOCATION**\n");
    printf("Enter number of files:");
    scanf("%d", &n);
    while(count!=n){
        printf("\nEnter file name %d:", count + 1);
        scanf("%s",name);
        printf("Enter starting block of file %d:", count + 1);
        scanf("%d",&start);
        printf("Enter no of blocks in file %d:", count + 1);
        scanf("%d",&r);
        for(j=0;j<r;j++){
        	b[j]=start+j;
		}
		int ch=check(a,b);
		if(ch==1){
			printf("\nPOSITION ALREADY OCCUPIED!!\n");
		}
		else{
		    ft[count].sb=start;
            ft[count].nob=r;
            strcpy(ft[count].name,name);
			for(j=0;j<r;j++){
				a[k]=b[j];
				k++;
			}
			count++;
		}
    }
    printf("\nEnter the file name to be searched:");
    scanf("%s", s);
    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0)
            break;
    } 
    if (i == n)
        printf("\nFile Not Found");
    else {
        printf("\nFILE_NAME\t START_BLOCK\t NO_OF_BLOCKS\t BLOCKS_OCCUPIED\n");
        printf("%s\t\t %d\t\t %d\t\t", ft[i].name, ft[i].sb, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++)
            printf("%d ", ft[i].sb + j);
    }
}
