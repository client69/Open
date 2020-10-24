#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top=-1;

void push(int x)
{
	if(top==MAX_SIZE-1)
	{	printf("Stack is Full\n");}
else
{
	A[++top]=x;
}

} 

void pop()
{
	if(top==-1) 
{
	printf("Stack is Empty\n");
}
	{top--;}
}

void print()
{
	for(int i=0;i<=top;i++)
	{
		printf("%d," ,A[i]);
	}
}
int main()
{
	push(1);print();
	printf("\n");
	push(2);print();
	printf("\n");
	push(3);print();
	printf("\n");
	pop();print();
	printf("\n");
	pop();print();
	printf("\n");
	pop();print();
	printf("\n");

	return 0;
}