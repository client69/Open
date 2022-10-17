#include<stdio.h>
int sort(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	  for(j=i+1;j<n;j++)
	  	if(a[i]>a[j])
	  	  {
	  	  	t=a[i];
	  	  	a[i]=a[j];
	  	  	a[j]=t;
	  	  }
	return a;
}
int main()
{
	int a[10],i,n,*p;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	printf("Enter Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	p=sort(a,n);
	printf("Sorted Elements Are:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
