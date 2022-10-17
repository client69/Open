#include<stdio.h>
int main()
{
	int l,c=0,i,j;
	char s1[5]="Army";
	char s2[5]="mrAy";
	for(i=0;s1[i]!='\0';i++)
	{
		for(j=0;s2[j]!='\0';j++)
		{
			if(s1[i]==s2[j])
				c++;
		}
	}
	l=strlen(s1);
	if(l==c)
	 printf("Both Are Same");
}
