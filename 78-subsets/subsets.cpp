class Solution {
public:
    void cal(int i,vector<int>op,vector<int>&ip,vector<vector<int>>&ans)
    {
        if(ip.size()==i)
        {
            ans.push_back(op);
            return;
        }
        cal(i+1,op,ip,ans);
        op.push_back(ip[i]);
        cal(i+1,op,ip,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        cal(0,op,nums,ans);
        return ans;
    }
};