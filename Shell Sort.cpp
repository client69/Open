//------ AI Programming ---------
// Shell Sort Algorithm
// Join our underground coding movement @freecodecs (c) June, 2019.

#include<iostream>
using namespace std;

int main()
{
	int size=10;
	int array[size];
	// Input
	cout<<"\nEnter size of elements: ";
	cin>>size;
	for (int i = 0; i < size; i++)
	{
		cout<<"\nEnter the "<<i+1<<" element: ";
		cin>>array[i];
	}

	// Sorting
	for (int i = size/2; i>0 ; i=i/2)
	{
		for (int j = i; j <size ; j++)
		{
			for (int k = j-i; k>=0; k=k-i)
			{
				if (array[k]<array[k+i])
				{
					break;
				}
				else
				{
					int temp=array[k+i];
					array[k+i]=array[k];
					array[k]=temp;
				}
			}
		}
	}

	// Output
	cout<<"\nSorted elements are: ";
	for (int i = 0; i < size; ++i)
	{
		cout<<array[i]<<", ";
	}
	return 0;
}