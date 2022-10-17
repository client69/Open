#include<stdio.h>
int main()
{
	int a[10],b[10],c[10],i,j,k,n,t=0,p=0;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	printf("Enter Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			b[t]=a[i];
			t++;
		}
		else
		{
			c[p]=a[i];
			p++;
		}
	}
	printf("All Even Numbers are:");
	for(i=0;i<t;i++)
		printf("%d ",b[i]);
	printf("All Odd Numbers are:");
	for(i=0;i<p;i++)
		printf("%d ",c[i]);
	return 0;
}
	

