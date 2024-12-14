class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int>st;
        st.insert(nums[0]);
        long long ans = 0;
        int i =0,j=0;
        while(i<n && j<n){
            while(abs(*(st.rbegin())-*(st.begin()))<=2){
                j++;
                if(j==n) break;
                st.insert(nums[j]);
            }
            long long t = j-i;
            ans += (t*(t+1))/2;
            if(j==n) break;
            while(abs(*(st.rbegin())-*(st.begin()))>2){
                st.erase(st.lower_bound(nums[i]));
                i++;
            }
            long long v = j-i;
            ans -= (v*(v+1))/2;
        }
        return ans;
    }
};