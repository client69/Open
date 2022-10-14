#include <stdio.h>
#include <stdlib.h>
#define size 100

struct student
{
    int rollno, marks;
    char name[size];

} s[5];
int i;
FILE *fp, *fp1;
void create()
{
    fp = fopen("d1.txt", "w");
    for (i = 0; i < 5; i++)
    {
        printf("enter roll no.");
        scanf("%d", &s[i].rollno);
        printf("enter name");
        gets(s[i].name);
        scanf("%s", &s[i].name);
        printf("\n enter marks(out of 100)");
        scanf("%d", &s[i].marks);
        fwrite(&s[i], sizeof(s), 1, fp);
    }
    fclose(fp);
}
void show()
{
    fp1 = fopen("d1.txt", "r");
    printf("\n roll no:\t name: \t marks: \n");
    for (i = 0; i < 5; i++)
    {
        while (fread(&s[i], sizeof(s), 1, fp1))
        {
            printf("\n %d \t\t %s \t\t %d \n", s[i].rollno, s[i].name, s[i].marks);
        }
    }
    fclose(fp1);
}
int main()
{
    int x;
    do
    {
        printf("\n Main Menu");
        printf("\n 1. Create Record");
        printf("\n 2. Show Record");
        printf("\n 3. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &x);
        switch (x)

        {
        case 1:
            create();
            break;
        case 2:
            show();
            break;
        case 3:
            exit(0);
            break;
        }

    } while (1);
}
