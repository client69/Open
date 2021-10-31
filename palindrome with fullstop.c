#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,c=0;
    char str[50], cpy[50]={},co[50];
    printf("enter string ");
    fgets(str,50,stdin);
    c=strlen(str);
    for(i=c-1,j=0; i>=0; i--,j++)
    {
        cpy[j]=str[i];
        co[j]=str[j];
    }
    if(strcmp(cpy,co)==0){
        printf("%s \n It is a palindrome",cpy);}
       else{
            printf("%s \n it is not a palindrome",cpy);
        }
    }