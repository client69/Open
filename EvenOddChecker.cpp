#include <iostream>
using namespace std;
int main()
{
    int num, rem;
    cout << "Enter any positive integer: ";
    cin >> num;
    rem = num % 2;
    if (rem == 0)
        cout << num << " is an EVEN integer " << endl;
    else
        cout << num << " is an ODD integer " << endl;

    return 0;
    
}