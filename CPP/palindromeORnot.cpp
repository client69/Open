#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    cin >> str;
    int flag = 1;
    int n = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[n - i - 1])
        {
            flag = 0;
            break;
        }
    }
    cout << flag;
}