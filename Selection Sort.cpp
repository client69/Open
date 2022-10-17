//------ AI Programming ---------
// Selection Sort Algorithm
// Join our underground coding movement @freecodecs (c) June, 2019.

#include<iostream>
using namespace std;

int main()
{
	int Array[6];
	cout<<"\nInsert any 6 Numbers for Unsorted Elements: ";
	
	//Input
	for(int i=0; i<6; i++)
	{
		cin>>Array[i];
	}
	
	//Selection Sorting
	for(int i=0; i<6; i++)
	{
		int min=i;
		for(int j=i+1; j<6; j++)
		{
			if(Array[j]<Array[min])
			{
				min=j; //Finding the smallest number in Array
			}
		}
		int temp =Array[i];
		Array[i]=Array[min];
		Array[min]=temp;
	}
	
	//Output
	cout<<"\nSorted Elements are : ";
	for(int i=0; i<6; i++)
	{
		cout<<Array[i]<<", ";
	}
}
