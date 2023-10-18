class Solution {
public:
    int dp[101][101];
    int rec(vector<int>&cuts,int i,int j,int m,int n){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int temp =INT_MAX;
        for(int k=i;k<j;k++){
            temp=min(temp, n-m + rec(cuts,i,k,m,cuts[k])+rec(cuts,k+1,j,cuts[k],n));
        }
        return dp[i][j]=temp;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return rec(cuts,0,cuts.size(),0,n);
    }
};