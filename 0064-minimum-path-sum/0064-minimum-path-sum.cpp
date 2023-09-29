class Solution {
public:

    int minPathSum(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int sum=0;
        int dp[n][m];
        for(int i=0;i<n;i++){
            sum+=g[i][0];
            dp[i][0]=sum;
        }
        sum=0;
        for(int i=0;i<m;i++){
            sum+=g[0][i];
            dp[0][i]=sum;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = g[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};