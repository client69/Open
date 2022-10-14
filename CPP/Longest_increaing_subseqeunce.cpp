#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int dp[n],result=0;
	    dp[0]=1;
	    int k=0;
	    for(int i=1;i<n;i++)
	    {
	        dp[i]=1;
	        for(int j=0;j<i;j++)
	        {
	            if(a[j]<a[i] && dp[i]<(dp[j]+1))
	                dp[i]=dp[j]+1;
	        }
	        result = max(result,dp[i]);
	    }
	    cout<<result<<endl;
	}
	return 0;
}
