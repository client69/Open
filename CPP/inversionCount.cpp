#include<bits/stdc++.h>
using namespace std;
long long helper(int A[], int start, int end)
{
    if(start >= end)
        return 0;
    int mid = (end + start) / 2;
    long long count = 0;
    count += helper(A, start, mid);
    count += helper(A, mid + 1, end);
    int i = start, j = mid + 1, k = 0;
    int copy[end - start + 1];
    while(i <= mid && j <= end)
    {
        if(A[j] < A[i])
        {
            count += end - i + 1;
            copy[k] = A[j];
            j++;
        }
        else if(A[j] > A[i])
        {
            copy[k] = A[i];
            i++;
        }
        k++;
    }
    while(i <= mid)
    {
        copy[k] = A[i];
        i++;
        k++;
    }
    while(j <= end)
    {
        copy[k] = A[j];
        j++;
        k++;
    }
    for(int l = 0; l <= (end - start); l++)
        A[start + i] = copy[i];
    return count;
}
long long solve(int A[], int n)
{
    return helper(A, 0, n - 1);
}
int main(int argc, char const *argv[])
{
    int A[] = {2, 5, 1, 3, 4};
    solve(A, 5);
    for(int i = 0; i < 5; i++)
        cout<<A[i]<<" ";
    return 0;
}
