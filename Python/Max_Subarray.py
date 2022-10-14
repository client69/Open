arr = [2, -10, 11, 3, 4, -5, 1]
sumTillNow, maxSum = 0, float('-inf')

for num in arr:
    sumTillNow += num
    maxSum = max(maxSum, sumTillNow)
    if (sumTillNow < 0):
        sumTillNow = 0

print(maxSum)
