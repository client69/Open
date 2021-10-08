//using map
#include <bits/stdc++.h>
using namespace std;

void fun(string str)
{

    int n = str.length();
    map<char, int> count;
    for (int i = 0; i < n; i++)
    {
        count[str[i]]++;
    }

    for (auto it : count)
    {
        if (it.second > 1)
            cout << it.first << " count = " << it.second << "\n";
    }
}

int main()
{
    string str;
    cin >> str;

    fun(str);
}