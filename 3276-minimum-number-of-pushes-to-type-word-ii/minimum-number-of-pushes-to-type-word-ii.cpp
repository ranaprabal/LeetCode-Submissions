class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mpp(26, 0);

        for (auto &it : word) {
            mpp[it - 'a']++;
        }
        sort(mpp.begin(), mpp.end());
        int ans = 0;
        for (int i = 25; i >= 0; i--) {
            if (mpp[i] == 0)
                break;
            ans += mpp[i] * ((25 - i) / 8 + 1);
        }

        return ans;
    }
};