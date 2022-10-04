#include <iostream>
using namespace std;
int main()
{
    int i,j,k,l;
    cin>>i;
    int a[i];
    for(j=0;j<i;j++)
    {   cin>>k;
        if(k%2==0)
            {a[j]=k/2;}
        else
            {a[j]=(k-1)/2;}
    }    
    for(l=0;l<i;l++)
    {cout<<a[l]<<"\n";}
}
