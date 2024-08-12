class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>v;
        v.push_back({1});
        for(int i=1;i<n;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<v[i-1].size();j++){
                temp.push_back(v[i-1][j]+v[i-1][j-1]);
            }
            temp.push_back(1);
            v.push_back(temp);
        }
        return v;
    }
};