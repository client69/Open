#include<iostream>
using namespace std;
void StoogeSort(int a[],int start, int end) {
   int temp;
   if(end-start+1 > 2) {
      temp = (end-start+1)/3;
      StoogeSort(a, start, end-temp);
      StoogeSort(a, start+temp, end);
      StoogeSort(a, start, end-temp);
   }
   if(a[end] < a[start]) {
      temp = a[start];
      a[start] = a[end];
      a[end] = temp;
    }
}
int main() {
   int m, i;
   cout<<"\nEnter the number of data element to be sorted: ";
   cin>>m;
   int arr[m];
   for(i = 0; i < m; i++) {
      cout<<"Enter element "<<i+1<<": ";
      cin>>arr[i];
   }
   StoogeSort(arr, 0, m-1);
   cout<<"\nSorted Data ";
   for (i = 0; i < m; i++)
      cout<<"->"<<arr[i];
   return 0;
}
