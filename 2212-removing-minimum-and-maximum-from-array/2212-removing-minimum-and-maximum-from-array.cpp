class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        pair<int,int>minn,maxx;
        minn={-1,INT_MAX};
        maxx={-1,INT_MIN};
        for(int i=0;i<n;i++){
            if(minn.second>nums[i]) minn = {i,nums[i]};
            if(maxx.second<nums[i]) maxx = {i,nums[i]};
        }
        int min2 = min(minn.first,maxx.first);
        int max2 = max(minn.first,maxx.first);
        
        return min(max2+1,min(n-min2,min2+1+n-max2));

    }
};