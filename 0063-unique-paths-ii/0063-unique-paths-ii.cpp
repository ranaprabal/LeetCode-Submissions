int static dp[101][101];
class Solution {
public:
    int rec(int n, int m, vector<vector<int>>&o){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(o[n][m]==1){
            dp[n][m]=0;
            return dp[n][m];
        }
        if(n==0 && m==0){
            dp[n][m]=1;
            return dp[n][m];
        } 
        dp[n][m] = rec(n-1,m,o)+rec(n,m-1,o);
        return dp[n][m];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        return rec(n-1,m-1,obstacleGrid);
    }
};