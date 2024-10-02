#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 50
int top=-1,i,j,k=0,result,s,value1,value2,re[10],flag,num;
char str[50],a[50],b[MAX];

int get_precedence(char operator){
	switch(operator){
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
	}
}
int associativity(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
			return 1; //L to R
		case '^':
			return 2;// R to L
	}
}
void push(char item){
	top=top+1;
	a[top]=item;
}

void pop() {
    top = top - 1;
}

void infix_postfix(char str[]){
	for(i=0;i<strlen(str)-1;i++){
		
		if(isdigit(str[i])){
			while(isdigit(str[i])){
				b[k]=str[i];
				k++;
				i++;
			}
			b[k] = ' '; 
            k++;
            i--;
		}
		else if(top==-1||a[top]=='('){
			push(str[i]);
		} 
		else if(str[i]=='('){
			push(str[i]);
		}
		else if(str[i]==')'){
			for(j=top;a[j]!='(';j--){
				b[k]=a[j];
				k++;
				pop();
			}
			top--;
		}
		else if(get_precedence(str[i])>get_precedence(a[top])){
			push(str[i]);
		}
		else if(get_precedence(str[i])<get_precedence(a[top])){
			
			flag=0;
			while(flag==0){
				if(get_precedence(str[i])>get_precedence(a[top])){
					push(str[i]);
					flag=1;	
				}
				else if(get_precedence(str[i])==get_precedence(a[top])){
					if(associativity(str[i])==1){
						b[k]=a[top];
						k++;
						pop();
						push(str[i]);
						flag=1;
					}
					else if(associativity(str[i])==2){
						push(str[i]);
						flag=1;
					}
					
				}
				else{
					b[k]=a[top];
					k++;
					pop();
				}
			}
		}
		else if(get_precedence(str[i])==get_precedence(a[top])){
			if(associativity(str[i])==1){
				b[k]=a[top];
				k++;
				pop();
				push(str[i]);
			}
			else if(associativity(str[i])==2){
				push(str[i]);
			}
    	}
	}
	while(top!=-1){
		b[k]=a[top];
		k++;
		pop();
	}
}
void postfix_evaluation(){

	for(s=0;b[s]!='\0';s++){
		
		if((b[s]>='0' && b[s]<='9')){
			num=0;
			while((b[s]>='0' && b[s]<='9')){
				num = num * 10 + (b[s] - '0');
				s++;
			}
			s--;
			top++;
			re[top]=num;
		}
		else if(b[s]=='+'||b[s]=='-'||b[s]=='*'||b[s]=='/'||b[s]=='^'){
			value1=re[top];
			pop();
			value2=re[top];
			pop();
			switch(b[s]){
				case '+':
					result = value2+value1;
					break;
				case '-':
					result = value2-value1;
					break;
				case '*':
					result = value2*value1;
					break;
				case '/':
					result = value2/value1;
					break;
				case '^':
					result = pow(value2,value1);
					break;
			}
			top++;
			re[top]=result;
		}
	}
	printf("%d",re[top]);
	pop();
}

int main(){
	printf("Enter the infix expression:");
	fgets(str, sizeof(str), stdin);
	printf("Infix expression: %s\n",str);
	infix_postfix(str);
	printf("\nAfter converting to postfix: ");
	puts(b);
	printf("\nAfter evaluation:");
	postfix_evaluation();
	return 0;
}
