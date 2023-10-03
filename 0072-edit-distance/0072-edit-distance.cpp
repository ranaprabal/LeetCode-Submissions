int dp[501][501];
class Solution {
    int rec(int n,int m,string &str1,string &str2){
        if(dp[n][m]!=-1) return dp[n][m];
        if(n==0 || m==0) return dp[n][m] = max(n+1,m+1);
        if(str1[n-1]==str2[m-1]){
            return dp[n][m] = rec(n-1,m-1,str1,str2);
        }    
        return dp[n][m] = 1 + min(min(rec(n,m-1,str1,str2),rec(n-1,m,str1,str2)),rec(n-1,m-1,str1,str2));
    }
public:
    int minDistance(string str1, string str2) {
        memset(dp,-1,sizeof(dp));
        int n=str1.size();
        int m = str2.size();
        return rec(n,m,str1,str2)-1;
    }
};