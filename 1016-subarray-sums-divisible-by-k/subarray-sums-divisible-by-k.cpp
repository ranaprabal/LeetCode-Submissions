class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        map<int, int> ans;

        int maxx = 0;

        for (auto& it : nums) {
            sum += it;
            if(sum<0){
                ans[abs((k+sum%k)%k)]++;
                maxx = max(maxx,ans[(abs(k+sum%k))%k]);
                continue;
            }
            ans[abs(sum % k)]++;
            maxx = max(maxx, ans[abs(sum % k)]);
        }

        int fact[maxx + 1];
        for (int i = 2; i <= maxx; i++) {
            fact[0] = 0;
            fact[1] = 0;
            fact[i] = i-1 + fact[i-1];
        }

        int ans2 = 0;
        if (ans.find(0) != ans.end())
            ans2 += ans[0];

        for (auto& it : ans) {
            if (it.second >= 2){
                ans2 += fact[it.second];
            }
        }
        return ans2;
    }
};