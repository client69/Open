///NICOI ALEXANDRU - tr0yyy
///cpp implementation of sum of array using divide et impera

#include <iostream>

using namespace std;

long v[1001] , n;

int sum(int p , int u)
{
    int m , nr1 , nr2;
    if(p == u)
        return v[p];
    else{
        m = (p + u) / 2;
        nr1 = sum(p,m);
        nr2 = sum(m+1,u);
        return nr1 + nr2;
    }
}

int main()
{
    cin >> n ;
    for(int i = 1 ; i <= n ; i++)
        cin >> v[i];
    cout << sum(1,n);
}
