int static dp[1001][1001];
class Solution {
public:
    int rec(int i,int j,string &str1,string &str2){
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==0) return 1;
        if(i==0) return 0;
        if(str1[i-1]==str2[j-1]){
            return dp[i][j] = rec(i-1,j-1,str1,str2) + rec(i-1,j,str1,str2);
        }
        else return dp[i][j] = rec(i-1,j,str1,str2);
    }
    int numDistinct(string str1, string str2) {
        memset(dp,-1,sizeof(dp));
        return rec(str1.size(),str2.size(),str1,str2);     
    }
};