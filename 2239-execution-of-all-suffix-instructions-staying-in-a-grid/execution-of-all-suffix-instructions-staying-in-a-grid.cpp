class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int j = 0; j < s.size(); j++) {
            int x = startPos[0], y = startPos[1];
            int count = 0;
            int i = j;
            while (x < n && y < n && x >= 0 && y >= 0 && i<s.size()) {
                if (s[i] == 'L') {
                    count++;
                    x = x + dx[1];
                    y = y + dy[1];
                }
                if (s[i] == 'R') {
                    count++;
                    x = x + dx[0];
                    y = y + dy[0];
                }
                if (s[i] == 'D') {
                    count++;
                    x = x + dx[2];
                    y = y + dy[2];
                }
                if (s[i] == 'U') {
                    count++;
                    x = x + dx[3];
                    y = y + dy[3];
                }
                i++;
            }
            if(x < n && y < n && x >= 0 && y >= 0) count++;
            ans.push_back(count-1);
        }
        return ans;
    }
};