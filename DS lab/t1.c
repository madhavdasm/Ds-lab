#include <stdio.h>
#include <string.h>
struct file{
    char name[100];
    int start;
    int range;
}f[10];
void main(){
    int num,temps,tempr,count=0,flag,i;
    char tempn[100];
    printf("Enter number of files : ");
    scanf("%d",&num);
    while(count!=num){
        printf("\nEnter the file name : ");
        scanf("\n%s",tempn);
        printf("Enter the start block : ");
        scanf("%d",&temps);
        printf("Enter the range : ");
        scanf("%d",&tempr);
        i=count-1;
        flag=1;
        while(i>=0){
            if(strcmp(tempn,f[i].name)==0)>=f[i].start){
                flag=0;
                break;
            }
            if(temps<=f[i].start && (temps+tempr-1)>=f[i].start){
                flag=0;
                break;
            }
            else if(temps>=f[i].start && temps<=(f[i].start+f[i].range-1)){
                flag=0;
                break;
            }
            i--;
        }
        if(flag==1){
            strcpy(f[count].name,tempn);
            f[count].start=temps;
            f[count].range=tempr;
            count++;
        }
        else
            printf("Error\n");
    }
    printf("\nEnter file name to check : ");
    scanf("\n%s",tempn);
    flag=0;
    for(i=0;i<num;i++){
        if(strcmp(tempn,f[i].name)==0){
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nNo such file exists\n");
    else{
        printf("\nFile name : %s\nStart block : %d\nNo. of blocks : %d\nBlocks occupied : ",f[i].name,f[i].start,f[i].range);
        for(int j=f[i].start;j<(f[i].start+f[i].range-1);j++)
            printf("%d,",j);
        printf("%d",f[i].start+f[i].range-1);
    }
}
