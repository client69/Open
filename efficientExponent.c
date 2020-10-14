//**Program to calculate exponent of the form m^n(m raised to n)**

#include<stdio.h>

//Conventional method using formula: pow(m,n) = m*m*m*...(n times)
int pow(int m, int n)
{
    if(n==0)
        return 1; //Since anything raised to zero is 1
    else
        return pow(m,n-1)*m;
}
//This function will have reduced number of steps and hence it is faster.
//For even powers eg. 2^8 = (2*2)^4  OR for odd powers eg. 2^9 = 2*((2*2)^4)
int exponent(int m, int n)
{
    if(n==0)
        return 1;
    if(n % 2 == 0)
        return exponent(m*m,n/2);
    else
        return m*exponent(m*m,(n-1)/2);
    

}



void main()
{
    
    int m,n;
    printf("\nEnter base: ");
    scanf("%d",&m);
    printf("\nEnter exponent: ");
    scanf("%d",&n);
    printf("\n(%d)^%d = %d ",m,n,pow(m,n));//Using the first function
    printf("\n(%d)^%d = %d ",m,n,exponent(m,n));//Using improved function

}

