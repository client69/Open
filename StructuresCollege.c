struct college
{
	char name[100];
	char city[50];
	int establishmentYear;
	float passPercentage;
};
int main()
{
	int n,i,j;
	scanf("%d",&n);
	struct college *s,temp;
	s=(struct college*)calloc(n,sizeof(struct college));
	for(i=0;i<n;i++)
	{
		scanf("%s",(s+i)->name);
		scanf("%s",(s+i)->city);
		scanf("%d",&(s+i)->establishmentYear);
		scanf("%f",&(s+i)->passPercentage);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(strcmp(((s+j)->name),((s+(j+1))->name))>0)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}	
		}
	}
	printf("Details of Colleges\n");
	for(i=0;i<n;i++)
	{
		printf("college %d\n",i+1);
		printf("Name : %s\n",(s+i)->name);
		printf("City : %s\n",(s+i)->city);
		printf("Year of establishment : %d\n",(s+i)->establishmentYear);
		printf("pass Percentage : %.2f\n",(s+i)->passPercentage);
	}
	
}
