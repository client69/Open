#include<bits/stdc++.h>
using namespace std;
int main() {
    int t = 0;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        int n = 0, cows = 0;
        map<long long , int> m;
        cin>>n>>cows;
        vector<long long> position(n, 0);
        for(int i = 0; i < n; i++)
            cin>>position[i];
        sort(position.begin(), position.end());
        m[position[0]] = 1;
        m[position[n - 1]] = 1;
        long long Min = position[n - 1] - position[0];
        for(int i = 2; i < cows; i++)
        {
            long long bigDis = LONG_MIN, bestPos = 0;
            auto itr = m.begin();
            itr++;
            for(; itr != m.end(); itr++)
            {
                long long a = itr->first;
                itr--;
                long long b = (itr)->first;
                itr++;
                long long mid = (a + b)/2;
                long long x = lower_bound(position.begin(), position.end(), mid) - position.begin();
                if(abs(position[x] - mid) > abs(position[x - 1] - mid))
                    x--;
                if(position.at(x) == a || position.at(x) == b)
                    continue;
                long long res = min(abs(a - position[x]), abs(b - position[x]));
                if(res > bigDis)
                {
                    bigDis = res;
                    bestPos = position.at(x);
                }
            }
            m[bestPos] = 1;
            Min = min(bigDis, Min);
        }
        cout<<Min<<endl;
    }
}