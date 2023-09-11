class Solution {
public:
    void rec(int &ans,vector<int>&nums,int sum,int n,int target)
    {
        if(n==0 && sum==target)
        {
            ans++;
            return; 
        }
        if(n==0) return;
        int sum1=sum-nums[n-1];
        sum=sum+nums[n-1];
        rec(ans,nums,sum1,n-1,target);
        rec(ans,nums,sum,n-1,target);
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int ans=0;
        rec(ans,nums,sum,n,target);
        return ans;
    }
};