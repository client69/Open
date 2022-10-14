#include<stdio.h>

int main()
{
	int i,J,K,n,A[n],temp;
	
	printf("Enter number of elements in an array: ");
	scanf("%d", &n);
	
	printf("\nEnter the elements in array:\n");
	
	for (i=0; i<=n-1; i++)
	{
		scanf("%d",&A[i]);
	}

    printf("\nThe original array is:\n");
	for (i=0; i<n; i++)
	{
		printf("%d ", A[i]);
	}
	
	for(K=1; K<=n-1; K++)
	{
		for(J=0; J<=(n-K-1); J++)
		{
			if(A[J]>A[J+1])
			{
				temp=A[J];
				A[J]=A[J+1];
				A[J+1]=temp;
			}
		}
	}
	
	printf("\n\nThe sorted array is:\n");
	for (i=0; i<n; i++)
	{
		printf("%d ", A[i]);
	}
	
    return 0;

}
