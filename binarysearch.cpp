#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);
    }

    return -1;
}

int main()
{
    int arr[100],n,x;
    cout<<"Enter no of elements in the array"<<endl;
    cin>>n;
    cout<<"Enter the elements of the array :"<<endl;
    for(int i = 0; i<n; i++)
    {
    	cin>>arr[i];
	}
    cout<<"Enter the Number that you want to search : "<<endl;
    cin>>x;
    int res = binarySearch(arr, 0, n, x);
    (res == -1) ? cout << "Number not present": cout << "Number present at index " << res;
    return 0;
}
