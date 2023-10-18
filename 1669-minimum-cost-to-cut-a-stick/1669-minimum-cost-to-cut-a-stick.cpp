class Solution {
public:
    unordered_map<string,int>dp;
    int rec(vector<int>&cuts,int i,int j,int m,int n){
        if(i>=j) return 0;
        string key = to_string(i)+" "+to_string(j)+" "+to_string(m)+" "+to_string(n);
        if(dp.find(key)!=dp.end()) return dp[key];
        int temp =INT_MAX;
        for(int k=i;k<j;k++){
            temp=min(temp, n-m + rec(cuts,i,k,m,cuts[k])+rec(cuts,k+1,j,cuts[k],n));
        }
        return dp[key]=temp;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        return rec(cuts,0,cuts.size(),0,n);
    }
};