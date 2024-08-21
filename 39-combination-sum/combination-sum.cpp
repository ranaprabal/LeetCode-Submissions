class Solution {
public:
void rec(vector<int>selectedCandidates,int idx,vector<int>&candidates,vector<vector<int>>&ans,int target){

    int curSum = 0;
    for(auto &it:selectedCandidates) curSum += it;
    if(curSum==target){
        ans.push_back(selectedCandidates);
        return;
    } 
    if(idx>=candidates.size()) return;
    if(curSum + candidates[idx]<=target){
        // not include case 
        rec(selectedCandidates,idx+1,candidates,ans,target);
        selectedCandidates.push_back(candidates[idx]);
        //include case
        rec(selectedCandidates,idx,candidates,ans,target);

    }else rec(selectedCandidates,idx+1,candidates,ans,target);
}



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        rec(op,0,candidates,ans,target);
        return ans;
    }
};