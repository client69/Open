#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int n;
    cin>>n;
    bool is_prime[n+1];
    long int spf[n+1];
    for(long int i=0 ; i<= n ;i++)
        spf[i] = i;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(long int i=2;i*i<= n ; i++)
    {
       if(is_prime[i]== true)
       {
           for(long long int j = 2*i;j<= n;j+=i)
           {
               is_prime[j] = false;
               if(spf[j]== j)
                spf[j] = i;
           }
       }

    }
    long int noofdiv = 1;
    while(n>1)
    {
        long int p = spf[n];
        long int q = 0;
        while(n%p==0)
        {
            q++;
            n/=p;
        }
        noofdiv *=(q+1);

    }
    cout<<"\n"<<noofdiv;



    return 0;
}

