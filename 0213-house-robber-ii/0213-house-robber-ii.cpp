int static dp[101][2];
class Solution {
public:
    int rec(int n,vector<int>&nums,int use){
        if(dp[n][use]!=-1){
            return dp[n][use];
        }
        if(n==0){
            dp[n][use]=0;
            return dp[n][use];
        }
        if(n==1 && use==0){
            dp[n][use]=nums[0];
            return dp[n][use];
        }
        if(n==1 && use==1){
            dp[n][use]=0;
            return dp[n][use];
        }
        if(n==nums.size()){
            dp[n][use] = max(rec(n-1,nums,0),rec(n-2,nums,1)+nums[n-1]);
            return dp[n][use];    
        }
        else{
            dp[n][use] = max(rec(n-1,nums,use),rec(n-2,nums,use)+nums[n-1]);
            return dp[n][use];
        }
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        int n=nums.size();
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
        return rec(n,nums,0);
    }
};