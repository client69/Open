#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    int i,key,j;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void print_array(int arr[],int n)
{
    int i;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}

int main()
{
  int arr[]={12,13,11,5,6};
  int n=sizeof(arr)/sizeof(arr[0]);
insertion_sort(arr,n);
print_array(arr,n);
return 0;
}