#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n,w;
	cin>>t;
	while(t--)
	{
	    cin>>n>>w;
	    int val[n],weight[n];
	    for(int i=0;i<n;i++)
	    cin>>val[i];
	    for(int i=0;i<n;i++)
	    cin>>weight[i];
	    int dp[n+1][w+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=w;j++)
	        {
	            if(i==0||w==0)
	            dp[i][j]=0;
	            else if(weight[i-1]<=j)
	            dp[i][j]=max(val[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
	            else
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	    cout<<dp[n][w]<<endl;
	}
	return 0;
}
