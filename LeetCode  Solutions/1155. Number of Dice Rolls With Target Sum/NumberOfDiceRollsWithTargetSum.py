
class Solution(object):
    def numRollsToTarget(self, n, k, target):
        mod = 1000000000+7
        dp =[[0 for i in range(target+1)] for j in range(n)]
        for i in range(n):
            for j in range(target+1):
                if i == 0:
                    dp[i][j] = 1 if j>=1 and j<=k else 0
                else:
                    for l in range(1,k+1):
                        if j-l>0:
                            dp[i][j]+=dp[i-1][j-l]
                            dp[i][j]%=mod
        return dp[n-1][target] % mod
    
#Driver code
ob = Solution()
print(ob.numRollsToTarget(2,6,7))