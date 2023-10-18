class Solution {
    int dp[302][302];
public:
    int rec(vector<int>&a,int i,int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int temp =INT_MIN;
        for(int k=i;k<j;k++){
            int right =a[j];
            int left =a[i-1];
            temp = max(temp,left*a[k]*right + rec(a,i,k)+rec(a,k+1,j));
        }
        return dp[i][j] = temp;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.emplace_back(1);
        memset(dp,-1,sizeof(dp));
        // for(auto it : nums) cout<<it<<" ";
        return rec(nums,1,nums.size()-1);
    }
};