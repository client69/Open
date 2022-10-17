#include<stdio.h>
int main()
{
	char str[100],count=0,i=0;
	scanf("%[^\n]",str);
	while(str[i]!='\0')
	{
		count++;
		i++;
	}
	printf("\n%d",count);
}
