class Solution {
public:
    void queen(vector<int>& cur, int i, set<pair<char,int>>& st,
               vector<vector<string>>& ans) {
        int n = cur.size();
        if (i == n) {
            string temp2 = "";
            for (int p = 0; p < n; p++) {
                temp2 += '.';
            }

            vector<string> str;
            for (int p = 0; p < n; p++) {
                str.push_back(temp2);
            }

            for (int p = 0; p < n; p++) {
                str[cur[p]][p] = 'Q';
            }

            ans.push_back(str);
            return;
        }

        for (int j = 0; j < n; j++) {
            bool f = false;
            for (int p = 0; p < i; p++) {
                if (j == cur[p]) {
                    f = true;
                    break;
                }
            }
            if (f)
                continue;
            if (st.find({'s',i + j}) == st.end() && st.find({'d',i - j}) == st.end()) {
                cur[i] = j;
                st.insert({'s',i + j});
                st.insert({'d',i - j});
                queen(cur, i + 1, st, ans);
                st.erase({'s',i + j});
                st.erase({'d',i - j});
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> cur(n, -1);
        set<pair<char,int>> st;
        vector<vector<string>> temp;
        queen(cur, 0, st, temp);
        return temp;
    }
};