struct student
{
	char name[100];
	int rno;
	long long int ph;
	int year;
};

main()
{
	int n=5,i;
	struct student *std;
	std=(struct student*)calloc(1,sizeof(struct student));
	/*if(std==NULL)
		printf("Memory is Not Allocated");*/
	printf("Enter Student Details: \n");
	for(i=0;i<n;i++)
	{
		printf("Name of std-%d: ",i+1);
		scanf("%s",(std+i)->name);
		printf("Roll Number of std-%d:",i+1);	
		scanf("%d",&(std+i)->rno);
		printf("Phone Number of std-%d: ",i+1);
		scanf("%lld",&(std+i)->ph);
		printf("Year of Study of std-%d: ",i+1);
		scanf("%d",&(std+i)->year);
	}
		printf("\n\nStudent Details Are: \n");
		for(i=0;i<n;i++)
		{
			printf("\nName of std-%d : %s",i+1,(std+i)->name);
			printf("\nRoll Numberof std-%d : %d",i+1,(std+i)->rno);
			printf("\nPhone Number of std-%d : %lld",i+1,(std+i)->ph);
			printf("\nYear of Study of std-%d : %d",i+1,(std+i)->year);
		}
}
