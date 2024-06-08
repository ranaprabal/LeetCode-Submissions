class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int sum =0;
        
        for(auto &it:nums){
            sum+=it;
            it=sum%k;
        }

        int n = nums.size();
        unordered_map<int,int>counter;

        for(int i=0;i<n;i++){
            if(i>0){
                if(nums[i]==0) return 1;
            }
            if(counter.find(nums[i])!=counter.end()){
                if(i-counter[nums[i]]>=2) return 1;
            }
            else counter[nums[i]] = i;
        }

        return 0;

    }
};