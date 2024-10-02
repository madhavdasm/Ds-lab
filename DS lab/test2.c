#include <stdio.h>
int max,f=0,r=0,a[10];
void insfrnt()
{
  if(f==(r%max)+1)
        printf("OVERFLOW\n");
    else
    {
     if(f==0 && r==0)
    {
        f=1;
        r=1;
    }
     else if(f==1)
      f=max;
     else
      f=f-1; 
     int item;
     printf("Enter the element:");
     scanf("%d", &item);
     a[f]=item;
    }
}
void insrer()
{
  if(f==(r%max)+1)
        printf("OVERFLOW\n");
    else
    {
     if(f==0 && r==0)
    {
        f=1;
        r=1;
    }
     else
       r=(r%max)+1;
     int item;
     printf("Enter the element:");
     scanf("%d", &item);
     a[r]=item;
    }
}
void delfrnt()
 {
    if(f==0)
        printf("UNDERFLOW\n");
    else
    {
      printf("Deleted item is: %d\n", a[f]);
      if(f==r)
      {
         f=0;
         r=0;
      }
      else
         f=(f%max)+1;
    }
}
 void delrer()
 {
    if(f==0)
        printf("UNDERFLOW\n");
    else
    {
      printf("Deleted item is: %d\n", a[r]);
      if(f==r)
      {
         f=0;
         r=0;
      }
      else if(r==1)
       r=max;
      else
       r=r-1; 
    }
}
void display()
  {
    if(f==0 && r==0)
        printf("Overflow,No value\n");
    else
    {
      int i=f;
      while(i!=r)
        {
          printf("%d\n",a[i]);
          i=(i%max)+1;
        }
      printf("%d\n", a[r]);
    }
}

void main() 
{
    int ch;
    printf("enter size of the Queue:");
    scanf("%d", &max);
    printf("*MENU*\n");
    printf("INPUT RESTRICTED QUEUE\n");
    printf("OUTPUT RESTRICTED QUEUE\n");
    do
    {
    printf("Enter your choice:");
    scanf("%d",&ch);
    if(ch==1)
    {
     int a;
     printf("1.INSERTION AT FRONT\n");
     printf("2.DELETION AT REAR\n");
     printf("3.DISPLAY\n");
     printf("4.DELETION AT FRONT\n");
     do
     {
      printf("enter your required choice:");
      scanf("%d",&a);
      switch(a)
        {
          case 1:
          insfrnt();
          break;
          case 2:
          delrer();
          break;
          case 3:
          display();
          break;
          case 4:
          delfrnt();
          default:
          printf("Invalid Choice\n");
        }
     }while(a>0 && a<5);
    } 
    else if(ch==2)
    {
     int a;
     printf("1.INSERTION AT REAR\n");
     printf("2.DELETION AT FRONT\n");
     printf("3.DISPLAY\n");
     printf("4.INSERTION AT FRONT:\n");
     do
     {
      printf("enter your required choice:");
      scanf("%d",&a);
      switch(a)
        {
          case 1:
          insrer();
          break;
          case 2:
          delfrnt();
          break;
          case 3:
          display();
          break;
          case 4:
          insfrnt();
          break;
          default:
          printf("Invalid Choice\n");
        }
     }while(a>0 && a<5);
    }
    else
      printf("WRONG CHOICE");
    }while(ch>0 && ch<3);  
}

