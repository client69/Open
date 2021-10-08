#include<stdio.h>

struct maxmin {
int max; int min;
};
struct maxmin M, N, O, P;

struct maxmin m(int arr[], int first,int last)
{  int mid;
   if (first==last)
   { M.max=arr[last];
     M.min=arr[last];
     return(M);
   }
   else if(last==first+1)
   {
      if (arr[first]>arr[last])
      { M.max=arr[first];
	M.min= arr[last];
	 return(M);
      }

     else
     {   M.max=arr[last];
	M.min= arr[first];
	 return(M);
     }
   }
   else
   {
    mid=(first+last)/2;
    N=m(arr, first, mid);
    O=m(arr, mid+1, last);
    if (N.max>O.max);
    else
       N.max=O.max;
    if(N.min<O.min);
    else
	N.min=O.min;
    return N;
    }
 }

void main()
{
  int i ,n;
  printf("enter size:\n");
  scanf("%d",&n);
  int arr[n];
  printf("enter elements:\n");
  for (i=0;i<n;i++)
    scanf("%d",&arr[i]); 
  P=m(arr,0,n-1);
  printf("\nmax element: %d \nmin element: %d", P.max, P.min);
  
}

