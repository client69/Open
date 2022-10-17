#include<stdio.h>
int main()
{
	int a[100],size,max,n,j,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter lenght:");
	scanf("%d",&size);
		for(i=0;i+size<=n;i++)
		{
			max=0;
			for(j=i;j<i+size;j++)	
			{
				if(max<a[j])
					max=a[j];
			}
			printf("%d ",max);
		}
		return 0;
}
