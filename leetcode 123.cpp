class Solution {
public:
    int dp[3][100005];
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       
        int mi = prices[0];
        
        for(int i=1;i<n;i++)
        {
            dp[1][i] = max(dp[1][i-1],prices[i] - mi);
            mi = min(mi,prices[i]);
        }
        int ma = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[2][i] = max(dp[2][i+1],ma - prices[i]);
            ma = max(ma,prices[i]);
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            res = max(res,dp[1][i-1]+dp[2][i]);
        }
        
        
        return res;
    }
};