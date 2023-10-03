static int dp[2001][2001];
class Solution {
public:

    bool rec(int n,int m,string &s,string &p){
        if(dp[n][m]!=-1) return dp[n][m];
        if(n==0 && m){
            if(p[m-1]=='*'){
                if(m==1) return dp[n][m] = 1;
                else return dp[n][m] = rec(n,m-1,s,p); 
            }
        }
        if(n==0 && m==0) return dp[n][m] = 1;
        if(n==0 || m==0) return dp[n][m] = 0;
        if(p[m-1]=='?' || s[n-1]==p[m-1]){
            return dp[n][m] = rec(n-1,m-1,s,p);
        }
        if(p[m-1]=='*'){
            return dp[n][m] = rec(n-1,m,s,p) || rec(n,m-1,s,p);
        }
        return dp[n][m] = 0;
    }
    bool isMatch(string s, string p) {
        bool r=true;
        int n1=s.size();
        int n2=p.size();
        string tempP="";
        for(int i=0;i<n2;i++) r=false;
        if(r && n2) return 1;
        memset(dp,-1,sizeof(dp));
        return rec(n1,n2,s,p);
    }
};