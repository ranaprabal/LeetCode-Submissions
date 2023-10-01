class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        if(totalsum%2) return false;
        totalsum/=2;
        int dp[n+1][totalsum+1];
        for(int i=0;i<totalsum+1;i++) dp[0][i]=0;
        for(int i=0;i<n+1;i++) dp[i][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<totalsum+1;j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][totalsum];
    }
};