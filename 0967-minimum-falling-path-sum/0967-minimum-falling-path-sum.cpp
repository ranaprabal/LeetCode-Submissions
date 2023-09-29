class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int n=g.size();
        if(n==1) return g[0][0];
        int dp[n][n];
        for(int i=0;i<n;i++) dp[0][i]=g[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j] = g[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                } else
                if(j==n-1){
                    dp[i][j]=g[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = g[i][j] + min(min(dp[i-1][j],dp[i-1][j+1]),dp[i-1][j-1]);
                }
            }
        }
        return *min_element(dp[n-1],dp[n-1]+n);
    }
};