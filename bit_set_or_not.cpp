
#include <iostream>
using namespace std;

int main()
{
    int n,i;
    while(1)
    {
    cin >> n >> i; // Zero based index
    int f = 1;
    f = f << i;
    int res = n&f; 
    if(res==0)
    cout << "false" << endl;
    else
    cout << "true" << endl;
    }
    return 0;
}
