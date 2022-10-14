#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    cin >> str;

    int n = str.length();
    int end = n - 1;
    int start = 0;

    while (start < n / 2)
    {
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
    cout << str;
}