class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        int remainder[60]={0};
        for(auto &it: time)
        {
            if(it%60==0)
            {
                count+=remainder[0];  
            }
            else
            {
                count+=remainder[60-(it%60)];
            }
            remainder[it%60]++;
        }
        return count;
    }
};