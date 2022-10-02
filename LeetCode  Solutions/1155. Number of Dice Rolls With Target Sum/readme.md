# 1155. Number of Dice Rolls With Target Sum

You have n dice and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the k^n total ways) to roll the dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 10^9 + 7.

Constraints:

1 <= n, k <= 30
1 <= target <= 1000

Example 1:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 2:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 10^9 + 7.