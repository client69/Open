bool isMatch(string s, string p) {

    int n = s.length();
    int m = p.length();
    
    int dp[n+1][m+1];
    
    dp[0][0] = 1;
    
    for(int i=1;i<n+1;i++)
    {
        dp[i][0] = 0;
    }
    
    for(int j=1;j<m+1;j++)
    {
        if(p[j-1]=='*')
        {
            dp[0][j] = dp[0][j-2];
        }
        else
            dp[0][j] = 0;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if((s[i-1]==p[j-1]) or p[j-1]=='.')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1]=='*')
            {
                dp[i][j] = dp[i][j-2];
                if(s[i-1]==p[j-2] or p[j-2]=='.')
                {
                    dp[i][j] = (dp[i][j-2] or dp[i-1][j]);
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
    
}
};
