#include<stdio.h>
int main()
{
	int a[100],temp,i,j,n;
	printf("Enter no.of elements: ");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<(n);i++)
	{
		for(j=0;j<(n);j++)
		{
			if(a[i]=a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
