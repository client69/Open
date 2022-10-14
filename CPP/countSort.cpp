#include <bits/stdc++.h>
using namespace std;

int findMax(int arr[], int n)       //to find max element of an array
{
    int m = arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i] > m)
            m = arr[i];
    } 

    return m;
}

void countSort(int arr[],int n)
{
    int max;
    max = findMax(arr,n);

    int Count[max + 1];             //Count-array of size max element of an array

    for (int i = 0; i < max+1; i++) //initializing Count with 0's
        Count[i] = 0;
    
    for (int  i = 0; i < n; i++)    
        Count[arr[i]]++;
    
    int i =0, j = 0;
    while (i < max+1)
    {
        if(Count[i] > 0){
            arr[j++] = i;
            Count[i]--;
        }
        else
            i++;
    }
}

int main(){

    int n;  
    cout<<"Enter size: \n";
    cin>>n;
    int arr[n];
    cout<<"Enter an array: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    countSort(arr,n);
    cout<<"Sorted array is :\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
