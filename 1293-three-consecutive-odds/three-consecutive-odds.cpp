class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int maxx=0,cur=0;
        for(auto &it:arr){
            if(it&1){
                cur++;
            } else cur=0;
            maxx=max(maxx,cur);
        }

        return maxx>2;

    }
};