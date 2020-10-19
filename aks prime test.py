#AKS prime test is the fastest deterministic prime test as of now, it executes in polynomial time, useful for big primes

def factorial(x):
    p=1
    for i in range(2,x+1):
        p*=i
    return p

def isprime(n):
    if n==1:
        return False
    if n<1:
        return None
    for i in range(n+1):
        if n-i<i:
            break
        p=factorial(n)//(factorial(i)*factorial(n-i))
        if p%n!=0 and p!=1:
            return False
    return True
