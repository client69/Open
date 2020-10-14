#include <stdio.h>
#include <time.h>

void insert_sort(int a[], int n)
{
    int i = 0, j = 0, k, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    printf("\n Sorted Array : ");
    for (k = 0; k < n; k++)
    {
        printf("%d \t", a[k]);
    }
}

int main()
{
    int i, j, n, a[5];
    time_t start, end;
    start = time(NULL);
    printf("\n Enter the size of array : ");
    scanf("%d", &n);

    printf("\n Enter the elements : \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    insert_sort(a, n);

    end = time(NULL);
    printf("\n Time taken by the program is %.3f seconds", difftime(end, start));
    return 0;
}