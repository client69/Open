main()
{
	int a[100],prod=1,n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	 	scanf("%d",&a[i]);
	for(j=0;j<n;j++)
	{
		if(a[j]>=0)
		{
			printf("%d  ",a[j]);
			prod*=a[j];
		}
	}
	printf("\nProduct=%d",prod);
		
}
