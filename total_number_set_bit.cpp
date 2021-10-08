/// use __builtin_popcountll()for long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while(n>0)
    {
    count++;
    n = n&n-1;
    }
    cout << count << endl;

    int n2,cnt=0;
    cin >> n2;
    while(n2>0)
    {
        if(n2&1>0) cnt++;
        n2 = n2>>1;
    }
    cout << cnt << endl;

    int i;
    cin >> i;
    cout << __builtin_popcount(i) << endl;

    return 0;
}
