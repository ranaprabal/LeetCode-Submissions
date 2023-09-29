int static dp[201][201];
class Solution {
public:
    int rec(int n,int m,vector<vector<int>>& g){
        if(n<0 || m<0){
            return INT_MAX - 8000000;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        if(n==0 && m==0){
            dp[n][m]=g[0][0];
            return dp[n][m];
        }
        dp[n][m] = g[n][m] + min(rec(n-1,m,g),rec(n,m-1,g));
        return dp[n][m];
    }

    int minPathSum(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(n-1,m-1,g);
    }
};