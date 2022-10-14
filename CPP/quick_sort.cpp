#include <iostream>

using namespace std;
int partition(int input[],int si,int ei)
{
    int pivot=input[si];
    int count=0;
    for(int i=si+1;i<=ei;i++)
    {
        if(input[i]<=pivot)
            count++;
    }
    int pi=count+si;
    input[si]=input[pi];
    input[pi]=pivot;
    int i=si;
    int j=ei;
    while(i<=pi && j>=pi)
    {
        if(input[i]<=pivot)
            i++;
        else if(input[j]>pivot)
            j--;
        else
        {
           int temp;
           temp=input[i];
           input[i]=input[j];
           input[j]=temp;
           i++;
           j--;
        }
    }
    return pi;
}

void qs(int input[],int si,int ei)
{
    if(si>=ei)
        return;
    int pi=partition(input,si,ei);
    qs(input,si,pi-1);
    qs(input,pi+1,ei);

}

void quickSort(int input[],int size)
{
     qs(input,0,size-1);

}

int main()
{
  int input[10],size;
  cin>>size;
  for(int i=0;i<size;i++)
    cin>>input[i];
  quickSort(input,size);
  cout<< "array after quick sort:";
  for(int i=0;i<size;i++)
    cout<<" "<<input[i];

}

