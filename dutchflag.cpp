//dutchflag problem to sort an array having three types of elements only.
#include <bits/stdc++.h>
using namespace std;

void dutchflagsorting(int a[], int n)
{
	int low = 0;
	int high = n - 1;
	int mid = 0;
	while (mid <= high) {
		switch (a[mid]) {
		case 0:
			swap(a[low++], a[mid++]);
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(a[mid], a[high--]);
			break;
		}
	}
}


int main()
{
	int arr[] = { 0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
    dutchflagsorting(arr, n);
    for(auto it:arr){
        cout<<it<<",";
    }
    return 0;
}


