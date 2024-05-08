class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>temp;
        int n = score.size();
        for(int i=0;i<n;i++){
            temp.push_back({score[i],i});
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        string place[3] = {"Gold Medal","Silver Medal","Bronze Medal"};

        vector<string>ans(n);

        for(int i=0;i<n;i++){
            if(i<3){
                ans[temp[i].second] = place[i];
            }
            else ans[temp[i].second] = to_string(i+1);
        }

        return ans;

    }
};