#include<stdio.h>
main()
{
	char ch[100];
	int i,j,c=0;
	scanf("%[^\n]s",ch);
	for(i=0;ch[i]!='\0';i++)
	{
		if((ch[i]>='a' && ch[i]<='z') || (ch[i]>='A' && ch[i]<='Z'))
		{
			printf("%c",ch[i]);N
		}
	}
}

