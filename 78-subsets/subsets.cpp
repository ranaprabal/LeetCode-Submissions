class Solution {
public:
    void cal(vector<int>op,vector<int>ip,vector<vector<int>>&ans)
    {
        if(ip.size()==0)
        {
            ans.push_back(op);
            return;
        }
        
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        cal(op1,ip,ans);
        cal(op2,ip,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        cal(op,nums,ans);
        return ans;
    }
};