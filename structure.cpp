#include<stdio.h>
#include<stdlib.h>
struct stdd
{
	char name[50];
	int rollno;
	int year;
	long long int phno;
};
int main()
{
	int n=5,i;
	struct stdd *st;
	st=(struct stdd*)calloc(1,sizeof(struct stdd));
	if(st==NULL)
	{
		printf("memory not allocated");
	}
	for(i=0;i<n;i++)
	{
	printf("enter student name :");
	scanf("%s",(st+i)->name);
	printf("enter student rollno :");
	scanf("%d",&(st+i)->rollno);
	printf("enter student year :");
	scanf("%d",&(st+i)->year);
	printf("enter student phone number :");
	scanf("%lld",&(st+i)->phno);
	}
	for(i=0;i<n;i++)
	{
	printf("\nstudent details are: \n");
	printf("\nenter student name :%s",(st+i)->name);
	printf("\nenter student rollno :%d",(st+i)->rollno);
	printf("\nenter student year :%d",(st+i)->year);
	printf("\nenter student phone number :%lld",(st+i)->phno);
	}
}
