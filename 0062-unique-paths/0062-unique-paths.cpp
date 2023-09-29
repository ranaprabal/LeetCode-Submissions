int static dp[101][101];
class Solution {
public:
    int rec(int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) {
            dp[i][j]=1;
            return dp[i][j];
        }
        dp[i][j] = rec(i-1,j)+rec(i,j-1);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return rec(m-1,n-1);
    }
};