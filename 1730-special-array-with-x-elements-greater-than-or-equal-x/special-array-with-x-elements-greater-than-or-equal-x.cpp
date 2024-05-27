class Solution {
public:
    int specialArray(vector<int>& nums) {
        int ans =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<1000;i++){
            auto temp = lower_bound(nums.begin(),nums.end(),i) - nums.begin();
            if(temp==nums.size()) break;
            // cout<<temp<<" "<<i<<" "<<bool(i==(nums.size()-temp))<<endl;
            if(i==nums.size()-temp){
                ans=i;
                break;
            } 
        }
        return ans==0?-1:ans;
    }
};