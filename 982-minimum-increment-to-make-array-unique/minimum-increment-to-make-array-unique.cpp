class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int prev = -1;
        int minn = 0,ans=0;
        for(int i=0;i<n;i++){
            if(prev!=nums[i]){
                if(minn>nums[i]){
                    prev=nums[i];
                    ans+=minn-nums[i];
                    minn++;
                }
                else {

                prev=nums[i];
                minn= nums[i]+1;
                }
            } 
            else{
                ans+=minn-nums[i];
                minn++;
            }
        }
        return ans;

    }
};