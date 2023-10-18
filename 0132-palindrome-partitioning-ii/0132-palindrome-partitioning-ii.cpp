class Solution {
public:
int dp[2001];
    bool isPali(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    int rec(string &s,int i){
        if(i==s.size()) return dp[i] =  0;
        int temp =INT_MAX;
        for(int j=i;j<s.size();j++){
            if(isPali(s,i,j)){
                int cost = 0;
                if(dp[j+1]!=-1) cost = dp[j+1];
                else cost = dp[j+1] = rec(s,j+1);
                temp = min(temp, 1 + cost);
            }
        }
        return dp[i] = temp;
    }
    int minCut(string str) {
        memset(dp,-1,sizeof(dp));
        return rec(str,0)-1;                                       
    }
};