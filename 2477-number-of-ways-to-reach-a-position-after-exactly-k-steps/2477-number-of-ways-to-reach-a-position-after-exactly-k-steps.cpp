int offset=1500;
int dp[3000][1001];
int MOD = 1e009 + 7;
class Solution {
public:
    int rec(int diff,int k){
        // cout<<k<<" "<<dp[diff+offset][k]<<endl;
        if(dp[diff+offset][k]!=-1) 
        {
            cout<<dp[diff+offset][k]<<endl;
            return dp[offset+diff][k]%MOD;
    }
        if(k==diff) return dp[offset+diff][k] = 1;
        if(diff>k || k==0) return dp[offset+diff][k] = 0;
        return dp[offset+diff][k] =  (rec(diff-1,k-1)%MOD + rec(diff+1,k-1)%MOD)%MOD;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(startPos-endPos);
        if(diff>k || (k-diff)%2==1){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return rec(diff,k);        
    }
};