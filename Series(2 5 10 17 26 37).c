#include<stdio.h>
void main()
{
	int n,i,s=2,res=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=(i*i)+1;
		res=res+s;
		printf("%d ",s);
	}
	printf("\n%d",res);	
}
