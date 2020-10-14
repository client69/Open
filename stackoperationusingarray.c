#include<stdio.h>
#include<process.h>
#define n 20

int stack[20];
int top = -1;
int item;

void push()
{
  if(top==n-1)
  { printf("\nStack OverFlow");
  }
  else
  { top=top+1;
    printf("\nEnter value : ");
    scanf("%d",&item);
    stack[top]=item;
  }
}

void pop()
{
  if(top == -1)
    printf("\nStack UnderFlow");
  else
  { printf("\nPopped Item : %d",stack[top]);
    top=top-1;
  }
}

void print()
{
  int i;
  if(top==-1)
    printf("\n Stack UnderFlow");
  else
  { for(i=top; i>=0; i--)
    {  printf("%d\t",stack[i]);
    }
  }
}

void main()
{ int x;
  do{ ;
  printf("\nSTACK USING ARRAY\n");
  printf("\n1.Push \n2.Pop \n3.Print \n4.Exit");
  printf("\nEnter Choice : ");
  scanf("%d",&x);

  switch(x)
  {  case 1: push();
     break;
     case 2: pop();
     break;
     case 3: print();
     break;
     case 4: exit(0);
     default:
      printf("\nInvalid Input\n");
      break;
  } 
 }while(1);
}
