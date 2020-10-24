#Catalan number to find possible number of unique Binary Search Trees given any integer n

#Catalan number is defined by the formula: C_n+1 = 2 * (2n+1)/(n+2) * C_n
#Time complexity for Catalan number is: T(n) = 4 ^ n/n^ (3/2) * (pi)^(1/2)
#Leetcode problem : 96
def number_of_unique_bst(n):
    C = 1
    for i in range(0,n):
        C = C * 2 * (2*i + 1)/(i+2)
    return int(C)