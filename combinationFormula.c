//Program for calculating Combinations.
#include<stdio.h>
//We need factorial funtion for the construction of combination function.
//Factorial: n! = n*(n-1)*(n-2)*(n-3)*...1
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

//Combination formula : nCr = n!/(r!*(n-r)!)
//Conventional function using formula:
//ITERATIVE VERSION
int comb(int n, int r)
{
    int t1,t2,t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1/(t2*t3);
}
//But we know, nCr = n-1Cr-1 + n-1Cr
//RECURSIVE FORMULA

int Rcomb(int n, int r)
{
    if(r==0||n==r)
        return 1;
    else
        return Rcomb(n-1,r-1) + Rcomb(n-1,r);
}

//Such functions are called EXCESSIVE RECURSION FUNCTIONS.
//To avoid such a problem, we use MEMOIZATION. We store results of a function call so that we can utilize it again for the same function call.
//But we can use MEMOIZATION because nCr = nC(n-r)
int f[20];
int Mcomb(int n, int r)
{
    if(r<=n/2)
    {
        if(r==0||n==r)
            return 1;
        else
            return Mcomb(n-1,r-1) + Mcomb(n-1,r);
    }


    else
    {

            if(f[n-r]==-1)
                f[n-r]=Mcomb(n,n-r);
            return f[n-r];
    }

}
void main()
{   int i;
    for(i=0;i<20;i++)
    {
        f[i]=-1;
    }
    printf("\n%d", Mcomb(5,3));
    printf("\n%d", Rcomb(5,3));
    printf("\n%d", comb(5,3));
}
