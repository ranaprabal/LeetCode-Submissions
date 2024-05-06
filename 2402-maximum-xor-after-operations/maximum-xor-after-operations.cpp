class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int maxx = *max_element(nums.begin(),nums.end());
        int ans = maxx;
        int temp = 1;
        while(maxx){
            if((maxx&1)==0){
                bool done = true;
                for(auto &it:nums){
                    if(it&1 && done){
                        ans^=temp;
                        done = false;
                    }
                    it/=2;
                }
            }
            else{
                for(auto &it:nums) it/=2;
            }
            temp*=2;
            maxx/=2;
        }
        return ans;
    }
};