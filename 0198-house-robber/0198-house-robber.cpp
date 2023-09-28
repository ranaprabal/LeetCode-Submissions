int static dp[101];
class Solution {
public:
    int rec(int n,vector<int>&nums){
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n==0){
            dp[n]=0;
            return dp[n];
        }
        if(n==1){
            dp[n]=nums[0];
            return dp[n];
        }
        dp[n] = max(rec(n-1,nums),rec(n-2,nums)+nums[n-1]);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<n+1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
        
        return rec(n,nums);
    }
};