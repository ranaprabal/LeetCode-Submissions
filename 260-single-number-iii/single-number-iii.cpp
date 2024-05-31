class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2)
        {
            return nums;
        }
        vector<int>ans;
        sort(nums.begin(),nums.end());
        bool f1=true;
        for(int i =0;i<(nums.size())*1ll-1;i=i+2)
        {
            if(f1 && nums[i]!=nums[i+1])
            {
                f1=false;
                ans.push_back(nums[i]);
                ans.push_back(nums[i+1]);
            }
            else if(nums[i]!=nums[i+1])
            {
                ans[1]=nums[i+1];
            }
        }
        return ans;
    }
};