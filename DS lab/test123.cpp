#include<stdio.h>
#include<ctype.h>
#include<string.h>
int i,j,k=0,s,re[50],result,val1,val2,flag,num,top=-1;
char a[50],b[50],str[50];

int precedence(char Operator){
	switch(Operator){
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
		default:
			return 0;
			break;
		}
}

int asso(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
			break;
		case '^':
			return 2;
			break;
		default:
			return 0;
	}
}

void push(char item){
	top++;
	a[top]=item;
}

void pop(){
	top--;
}

void prefix(char str[]){
	for(i=strlen(str);i>=0;i--){
		if(isalnum(str[i])){
			while(isalnum(str[i])){
				b[k]=str[i];
				k++;
				i--;
			}
			b[k]=' ';
			i++;
		}
		else if(top==-1||a[top]=='('||str[i]=='('){
			push(str(i));
		}
		else if(str[i]==')'){
			for(j=top;a[j]!='(';j--){
				b[k]=a[j];
				k++;
				pop();
			}
			top--;
		}
		else if(precedence(str[i])>precedence(a[top])){
			push(str[i]);
		}
		else if(precedence(str[i])<precedence(a[top])){
			flag=0;
			while(flag==0){
			if(precedence(str[i])>precedence(a[top])){
				push(str[i]);
				flag=1;
			}
			else if(precedence(str[i])==precedence(a[top])){
				if(asso(str[i])==2){
					b[k]=a[top];
					k++;
					pop();
					flag=1;
				}
				else if(asso(str[i]==1)){
					push(str[i]);
					flag=1;
				}
			}
			else{
				b[k]=str[i];
				k++;
				pop();
			}
		}
	}
	else if(precedence(str[i])==precedence(a[top])){
				if(asso(str[i])==2){
					b[k]=a[top];
					k++;
					pop();
					flag=1;
				}
				else if(asso(str[i]==1)){
					push(str[i]);
					flag=1;
				}
			}
    }
    while(a[top]!=-1){
    	b[k]=a[top];
    	k++;
    	pop();
	}
}

void main(){
	printf("enter infix exp:");
	gets(str);
	printf("cpnverted exp is:\n");
	for(int m=k-1;m>=0;m--){
		printf("%c",b[k]);
	}
}
