#include<stdio.h>
void main()
{
	int i,n,j,s=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1)
				printf("%d",s);
			else
				printf("%d*",s);
		s++;
		}
		printf("\n");
	}
}
