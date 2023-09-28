class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1][2];
        dp[0][1]=dp[0][0]=0;
        dp[1][0]=nums[0];
        dp[1][1]=0;
        for(int i=2;i<n+1;i++){
            for(int j=0;j<2;j++){
                if(i==n){
                    dp[i][j]=max(dp[i-1][0],dp[i-2][1]+nums[n-1]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-2][j]+nums[i-1]);
                }
            }
        }
        return dp[n][0];
    }
};