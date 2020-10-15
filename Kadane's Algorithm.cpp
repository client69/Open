/*
Pseudocode

Kadane's Algorithm(array[1..n])
begin
    (maxSum, maxStartIndex, maxEndIndex) := (-INFINITY, 0, 0)
    currentMaxSum := 0
    currentStartIndex := 1
    for currentEndIndex := 1 to n do
        currentMaxSum := currentMaxSum + array[currentEndIndex]
        if currentMaxSum > maxSum then
            (maxSum, maxStartIndex, maxEndIndex) := (currentMaxSum, currentStartIndex, currentEndIndex)
        endif

        if currentMaxSum < 0 then
            currentMaxSum := 0
            currentStartIndex := currentEndIndex + 1
        endif
    endfor

    return (maxSum, maxStartIndex, maxEndIndex)
end

*/

#include<iostream> 
#include<climits> 
using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
	int max_so_far = INT_MIN, max_ending_here = 0; 

	for (int i = 0; i < size; i++) 
	{ 
		max_ending_here = max_ending_here + a[i]; 
		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 

		if (max_ending_here < 0) 
			max_ending_here = 0; 
	} 
	return max_so_far; 
} 

/*Driver program to test maxSubArraySum*/
int main() 
{ 
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int max_sum = maxSubArraySum(a, n); 
	cout << "Maximum contiguous sum is " << max_sum; 
	return 0; 
} 
