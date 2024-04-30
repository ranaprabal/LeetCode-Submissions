class Solution {
public:

    void dfs(int cur,int par,vector<vector<int>>&adj,vector<int>path,vector<vector<int>>&ans){
        if(cur == adj.size()-1){
            ans.push_back(path);
            return;
        }
        
        for(auto &it:adj[cur]){
            if(it!=par){
                vector<int>path2 = path;
                path2.push_back(it);
                dfs(it,cur,adj,path2,ans);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        path.push_back(0);
        dfs(0,-1,graph,path,ans);
        return ans;

    }
};