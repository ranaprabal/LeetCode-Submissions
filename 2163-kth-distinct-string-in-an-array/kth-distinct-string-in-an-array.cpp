class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>st;
        
        for(auto &it:arr){
            st[it]++;
        }

        for(auto &it:arr){
            if(st[it]==1) k--;
            if(k==0) return it;
        }


        return "";
    }
};