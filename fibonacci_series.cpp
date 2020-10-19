in mod = 1000000007;
#define M 32

struct matrix{
  in a,b,c,d;
};

struct matrix fibMatrix[100];

void PreComputation(in mod){
    
    fibMatrix[0].a = fibMatrix[0].b = fibMatrix[0].c = 1;
    fibMatrix[0].d = 0;
    
    for(in i=1;i<10;i++){
        
        fibMatrix[i].a = (((fibMatrix[i-1].a %mod) * (fibMatrix[i-1].a %mod))%mod 
        + ((fibMatrix[i-1].b %mod) * (fibMatrix[i-1].c %mod))%mod)%mod;
        
        fibMatrix[i].b = (((fibMatrix[i-1].a %mod) * (fibMatrix[i-1].b %mod))%mod 
        + ((fibMatrix[i-1].b %mod) * (fibMatrix[i-1].d %mod))%mod)%mod;
        
        fibMatrix[i].c = (((fibMatrix[i-1].c %mod) * (fibMatrix[i-1].a %mod))%mod 
        + ((fibMatrix[i-1].d %mod) * (fibMatrix[i-1].c %mod))%mod)%mod;
        
        fibMatrix[i].d = (((fibMatrix[i-1].c %mod) * (fibMatrix[i-1].b %mod))%mod 
        + ((fibMatrix[i-1].d %mod) * (fibMatrix[i-1].d %mod))%mod)%mod;
    }
}

in findFib(in n){
    
    if(n == 0) return 0;
    if(n == 1) return 1;
    n = n-2;
    in temp = 1;
    in index = 0;
    struct matrix ans_matrix;
    ans_matrix.a = ans_matrix.d = 1;
    ans_matrix.b = ans_matrix.c = 0;
    
    while(temp<=n){
        if(temp&n){
            // cout<<"index "<<index<<endl;
            struct matrix temp_matrix;
            temp_matrix.a = (((ans_matrix.a %mod) * (fibMatrix[index].a %mod))%mod 
            + ((ans_matrix.b %mod) * (fibMatrix[index].c %mod)))%mod;
            temp_matrix.b = (((ans_matrix.a %mod) * (fibMatrix[index].b %mod))%mod 
            + ((ans_matrix.b %mod) * (fibMatrix[index].d %mod)))%mod;
            temp_matrix.c = (((ans_matrix.c %mod) * (fibMatrix[index].a %mod))%mod 
            + ((ans_matrix.d %mod) * (fibMatrix[index].c %mod)))%mod;
            temp_matrix.d = (((ans_matrix.c %mod) * (fibMatrix[index].b %mod))%mod 
            + ((ans_matrix.d %mod) * (fibMatrix[index].d %mod)))%mod;
            ans_matrix = temp_matrix;
        }
        index++;
        temp = temp<<1;
    }
    
    return (((ans_matrix.a %mod) + (ans_matrix.b%mod))%mod);
    
}
// the above program is too complicated to understand try this one 
//my cpp program
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t1 = 0, t2 = 1, next = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if(i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        next = t1 + t2;
        t1 = t2;
        t2 = next;
        
        cout << next << " ";
    }
    return 0;
}
