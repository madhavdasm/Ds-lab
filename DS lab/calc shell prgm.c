void main()
{
	int a,b,c=0;
	char ch;
	printf("+.Addition\n-.Subtraction\nX.Multiplication\n/.Division\nEnter choice\n");
	scanf("%c",&ch);
	printf("Enter first no\n");
	scanf("%d",&a);
	printf("Enter second no\n");
	scanf("%d",&b);
	if(ch=='+'){
		c=a+b;
		printf("Sum of %d and %d is %d",a,b,c);
	}
	else if(ch=='-'){
		c=a-b;
		printf("diff of %d and %d is %d",a,b,c);
	}
	else if(ch=='X'){
		c=a*b;
		printf("pdt of %d and %d is %d",a,b,c);
	}
	else if(ch=='/'){
		c=a/b;
		printf("division of %d and %d is %d",a,b,c);
	}
	else{
		printf("Error");
	}
}
