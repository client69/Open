#include<bits/stdc++.h>
//covid cpp
using namespace std;

int main()
{
    int t = 0;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int size = 0;
        cin>>size;
        vector<int> v(size, 0);
        for (int j = 0; j < size; j++)
            cin>>v[j];
        int a = -1, flag = 0;
        for(int j = 0; j < size; j++)
        {
            if(v[j] == 1)
            {
                if(a == -1)
                    a = j;
                else
                {
                    if(j - a < 6)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        a = j;
                    }
                }
            }
        }
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;        
    }
    return 0;
}
