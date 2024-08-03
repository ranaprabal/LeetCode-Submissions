class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>c(1001,0);
        for(int i=0;i<target.size();i++){
            c[target[i]]++;
            c[arr[i]]--;
        }
        for(int i=0;i<1001;i++){
            if(c[i]!=0) return 0;
        }
        return 1;

    }
};