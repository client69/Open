#include<stdio.h>
int main()
{
	int x=1,y,s=0,a[100],i=0,b;
	printf("Enter number: ");
	scanf("%d",&y);
	while(x<=y)
	{
		if(x%2==0)
		{
			s+=x;
			a[i]=x;
			i++;
		}
		x++;
	}
	printf("sum of even numbers: %d \n",s);
	for(b=0;b<i;b++)
	{
		printf("%d  ",a[b]);
	}
}

