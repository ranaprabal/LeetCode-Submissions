class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        for(auto &it:nums){
            sum+=it;
            it=sum;
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        for(auto it:nums){
            int temp_diff = it-goal;
            if(mp.find(temp_diff)!=mp.end()){
                ans+=mp[temp_diff];
            }
            mp[it]++;
        }
        return ans;
    }
};