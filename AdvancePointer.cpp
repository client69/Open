#include<iostream>

using namespace std;

int main()
{
	int num[3];
	int* p;
	p=num;
	*p=10;
	p++;
	*p=20;
	p=&num[2];
	*p=30;
	for(int i=0; i<3; i++)
		cout<<num[i]<<" ";
	cout<<endl;
	return 0;
}