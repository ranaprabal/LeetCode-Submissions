class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        string one = "Push";
        string zero = "Pop";
        int temp=0;
        vector<string>ans;
        for(int i=1;i<=n && temp<m;i++){
            if(i==target[temp]){
                ans.push_back(one);
                temp++;
            }
            else{
                ans.push_back(one);
                ans.push_back(zero);
            }
        }
        return ans;
    }
};