#include <stdio.h>
int a[10][10],b[10][10],Trans[10][3],i,j,m,n,p,q;
void read(int d[][10],int s,int t){
    printf("Enter elements:");
    for(i=0;i<s;i++){
        for(j=0;j<t;j++){
            scanf("%d",&d[i][j]);
        }
    }
}
void print(int d[][3],int x){
    for(i=0;i<=x;i++){
        for(j=0;j<3;j++){
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
}
int sparse(int d[][10],int s,int t,int c[][3]){
    int count=0,index=1;
    c[0][0]=s;
    c[0][1]=t;
    for(i=0;i<s;i++){
        for(j=0;j<t;j++){
            if(d[i][j]!=0){
                c[index][0]=i;
                c[index][1]=j;
                c[index][2]=d[i][j];
                count++;
                index++;
            }
        }
    }
    c[0][2]=count; 
return count;
} 
int trans(int d[10][3]){
    int index=1;
    Trans[0][0]=d[0][1];
    Trans[0][1]=d[0][0];
     Trans[0][2]=d[0][2];
    for(i=0;i<d[0][1];i++){
        for(j=1;j<=d[0][2];j++){
            if(d[j][1]==i){
                Trans[index][0]=d[j][1];
                Trans[index][1]=d[j][0];
                Trans[index][2]=d[j][2];
                index++;
            }
        } 
    }
    return d[0][2];
}
void sum(int c[][3],int d[][3]){
    int s[10][3],p=1,q=1,t=1;
    if(c[0][0]==d[0][0]&&c[0][1]==d[0][1]){
        printf("Sum sparse matrix is\n");
      while(p<=c[0][2]&&q<=d[0][2]){
        if(c[p][0]>d[q][0]){
            s[t][0]=d[q][0];
            s[t][1]=d[q][1];
            s[t][2]=d[q][2];
            t++;
            q++;
        }
        else if(c[p][0]<d[q][0]){
            s[t][0]=c[p][0];
            s[t][1]=c[p][1];
            s[t][2]=c[p][2];
            t++;
            p++;
        }
        else{
            if(c[p][1]>d[q][1]){
            s [t][0]=d[q][0];
            s[t][1]=d[q][1];
            s[t][2]=d[q][2];
            t++;
            q++;
        }
        else if(c[p][1]<d[q][1]){
            s[t][0]=c[p][0];
            s[t][1]=c[p][1];
             s[t][2]=c[p][2];
            t++;
            p++;
        }
        else{
            s[t][0]=c[p][0];
            s[t][1]=c[p][1];
            s[t][2]=c[p][2]+d[q][2];
            t++;
            p++;
            q++;
        }
        }
}
		while(p<=c[0][2]){
			s[t][0]=c[p][0];
            s[t][1]=c[p][1];
            s[t][2]=c[p][2];
            t++;
            p++;
        }
		while(q<=d[0][2]){
		    s[t][0]=d[q][0];
            s[t][1]=d[q][1];
            s[t][2]=d[q][2];
            t++;
            q++;
		}
	s[0][0]=c[0][0];
	s[0][1]=c[0][1]	;
	s[0][2]=t-1;
    print(s,t-1);
}
    else
      printf("Addition is not possible!");
  }
void main(){
    int spa1[10][3],spa2[10][3],c;
    printf("Enter no of rows of first matrix:");
    scanf("%d",&m);
    printf("Enter no of columns of first matrix:");
    scanf("%d",&n);
    read(a,m,n);
    printf("Enter no of rows of second matrix:");
    scanf("%d",&p);
    printf("Enter no of cloumns of second matrix:");
    scanf("%d",&q);
    read(b,p,q);
    printf("Sparse matrix of first matrix\n");
    c=sparse(a,m,n,spa1);
    print(spa1,c);
    printf("Sparse matrix of second matrix\n");
    c=sparse(b,p,q,spa2);
    print(spa2,c);
    printf("Transpose sparse matrix of first matrix\n");
    c=trans(spa1);
    print(Trans,c);
    printf("Transpose sparse matrix of second matrix\n"); 
    c=trans(spa2);
    print(Trans,c);
    sum(spa1,spa2);
}
