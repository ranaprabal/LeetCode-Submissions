class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> low_ind(26, INT_MAX);
        vector<int> high_ind(26, -1);

        for (int i = 0; i < s.size(); i++) {
            low_ind[s[i] - 'a'] = min(i, low_ind[s[i] - 'a']);
            high_ind[s[i] - 'a'] = max(i, high_ind[s[i] - 'a']);
        }


        for (int i = 0; i < 26; i++) {
            if (high_ind[i] == -1)
                continue;
            for (int j = 0; j < 26; j++) {
                if (high_ind[j] == -1 || i==j)
                    continue;
                if (low_ind[i] < low_ind[j] && high_ind[i] > low_ind[j]) {
                    low_ind[i] = min(low_ind[i], low_ind[j]);
                    high_ind[i] = max(high_ind[i], high_ind[j]);
                    low_ind[j] = INT_MAX;
                    high_ind[j] = -1;
                    cout<<char(i+'a')<<" "<<char(j+'a')<<endl;
                }
                else
                if (low_ind[j] < low_ind[i] && high_ind[j] > low_ind[i]) {
                    low_ind[i] = min(low_ind[i], low_ind[j]);
                    high_ind[i] = max(high_ind[i], high_ind[j]);
                    low_ind[j] = INT_MAX;
                    high_ind[j] = -1;
                    cout<<char(i+'a')<<" "<<char(j+'a')<<endl;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            if (high_ind[s[i] - 'a'] != -1) {
                ans.push_back(high_ind[s[i] - 'a'] - low_ind[s[i] - 'a'] + 1);
                low_ind[s[i] - 'a'] = INT_MAX;
                high_ind[s[i] - 'a'] = -1;
            }
        }
        return ans;
    }
};