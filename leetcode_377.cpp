class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){
            for(int &x:nums){
                if(x>i) break;
                dp[i]+=dp[i-x];
            }
        }
        return dp[target];
    }
};