// ---- AI Programming ------
// Implementation of QuickSort using C++
// Join our underground coding movement
// @freecodecs (c) May, 2019

#include<iostream>
using namespace std;

//swaping two elements high & low fuction
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

//partitioning fuction
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

//quicksort emplementation function
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        // assigning pi
        int pi = partition(arr, low, high); 
  
        // sort elements before and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
 
 //display sorted elements fuction
void display(int arr[], int size) 
{ 
    for (int i=0; i < size; i++) 
        cout<<arr[i]<<", ";  
} 

int main()
{
	//declaring and accepting size of an arry
    int size;
    cout<<"\nEnter the size of elements : ";
    cin>>size;

    int arr[size];
    
    cout<<"\nBy using space enter the unsorted elements : ";

    for (int i = 0; i < size; ++i)
    {
        cin>>arr[i];
    }
    quickSort(arr, 0, size-1); 
    cout<<"\nSorted elements are : ";
    display(arr, size);
    return 0;
}
