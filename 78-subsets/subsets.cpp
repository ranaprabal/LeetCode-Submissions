class Solution {
public:
    void cal(int i,vector<int>op,vector<int>&ip,vector<vector<int>>&ans)
    {
        if(ip.size()==i)
        {
            ans.push_back(op);
            return;
        }
        
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(ip[i]);
        cal(i+1,op1,ip,ans);
        cal(i+1,op2,ip,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        cal(0,op,nums,ans);
        return ans;
    }
};