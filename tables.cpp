#include<stdio.h>
int main()
{
	int n,i=1;
	printf("Enter number: ");
	scanf("%d",&n);
	do{
		printf("%d X %d = %d",n,i,(n*i));
		printf("\n");
		i++;
	}while(i<11);
}

