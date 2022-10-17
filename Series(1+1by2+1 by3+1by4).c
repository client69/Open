#include<stdio.h>
int main()
{
	int n,i;
	double s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			printf("%d+",i);
		}
		else if(i!=n)
		{
			printf("+1/%d",i);
		}
		else
		{
			printf("1/%d+",i);
		}
		s=s+(i+1);
	}
	printf("\n%d",s);
	return 0;
}
