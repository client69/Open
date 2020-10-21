#AKS prime test a deterministic prime test, it executes in polynomial time, useful for really big primes

def factorial(x):
    p=1
    for i in range(2,x+1):
        p*=i
    return p

def isprime(n):
    if type(n)!=int or n<1:
        raise ValueError
    if n==1:
        return False
    for i in range(n+1):
        if n-i<i:
            break
        p=factorial(n)//(factorial(i)*factorial(n-i))
        if p%n!=0 and p!=1:
            return False
    return True
