#include<stdio.h>
#include<string.h>
void main()
{
char s[30],line[30];
int vow=0,cons=0,i=0,space=0;
printf("\nenter the string");
gets(strlwr(line));
//line=strlwr(s);
while(line[i]!='\0')
{

if (line[i] =='a' || line[i] =='e' ||
line[i] == 'i' || line[i] == 'o' ||
line[i] == 'u')

{

vow++;

}

else if (line[i] ==' ')

{

++space;

}

else

{

cons++;

}
}
printf("No of vowels=%d\nNo of spaces=%d\nNo of consonants=%d",vow,space,cons);

}

