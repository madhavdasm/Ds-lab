#include <stdio.h>
#include <string.h>
struct fileTable
{
    char name[20];
    int nob, blocks[30];
    int flag;
} ft[30];
int k,block,a[50],x=0;

int check(int a[],int j,int block,int b[]){
	for(k=0;k<30;k++){
		if(block==a[k]){
			return 1;
		}
    }
    for(k=0;k<j;k++){
		if(block==b[k]){
			return -1;
			
		}		
	}
	return 0;
}

void main()
{
    int i, j, n,nob,count=0,ch;
    char s[20],name[20];
    
    printf("**LINKED FILE ALLOCATION**\n");
    printf("Enter no of files: ");
    scanf("%d", &n);
    while(count!=n)
    { 
        int flag=0;
        printf("\nEnter file name %d: ", count + 1);
        scanf("%s",name);
        printf("Enter no of blocks in file %d: ", count + 1);
        scanf("%d",&nob);
        int b[nob];
        printf("Enter the blocks of the file one by one: ");
        for (j = 0; j < nob; j++){
            scanf("%d",&block);
            ch=check(a,j,block,b);
            if(ch==1||ch==-1){
		        printf("\nALREADY OCCUPIED!!\n");
		        ft[count].flag=1;
		        flag=1;
		        break;
	        }
	        else{
                b[j]=block;
	}
    } 
    if(flag!=1){
    for(i=0;i<nob;i++){
    	strcpy(ft[count].name,name);
        ft[count].nob=nob;
        a[x]=b[i];
		x++;
		ft[count].flag=0;
	    ft[count].blocks[i]=b[i];
	}
}  
    if(ch==0)
	   count++;
}
    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);
    for (i = 0; i < n; i++)
    {
        if (strcmp(s, ft[i].name) == 0)
            break;
    }

    if (i == n||ft[i].flag==1)
    {
        printf("\nFile Not Found");
    }
    else
    {
        printf("\n FILE_NAME\tNO_OF_BLOCKS\t BLOCKS_OCCUPIED");
        printf("\n %s\t\t %d\t\t", ft[i].name, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++){
            printf("%d", ft[i].blocks[j]);
            if(j!=ft[i].nob-1){
            	printf("->");
			}
    }
}
}
