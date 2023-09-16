class Solution {
public:
    bool rec(vector<vector<int>>&t,vector<int>&nums,int n,int sum)
    {
        if(t[n][sum]!=-1) return t[n][sum]>0;
        if(sum==0)
        {
            t[n][sum]=1;
            return t[n][sum]>0;
        }
        if(n==0)
        {
            t[n][sum]=0;
            return t[n][sum]>0;
        }
        if(sum>=nums[n-1])
        {
            t[n][sum]=(rec(t,nums,n-1,sum-nums[n-1]) + rec(t,nums,n-1,sum));
            return t[n][sum]>0;
        }
        else{
            t[n][sum]=rec(t,nums,n-1,sum);
            return t[n][sum]>0;
        }
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        if(totalsum%2) return false;
        totalsum/=2;
        vector<vector<int>>t(n+1,vector<int>(totalsum+1,-1));
        return rec(t,nums,n,totalsum);
    }
};