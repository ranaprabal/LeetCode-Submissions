class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>temp = heights;
        sort(temp.begin(),temp.end());
        int count =0;
        for(int i=0;i<temp.size();i++){
            count+=temp[i]!=heights[i];
        }
        return count;
    }
};