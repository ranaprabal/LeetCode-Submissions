class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>mpp;
        int count=0;
        for(auto &it : time)
        {
            mpp[it%60]++;
            int toFind=60-(it%60);
            if(mpp.find(toFind)!=mpp.end() && toFind!=30)
            {
                count+=mpp[toFind];
            }
            else if(mpp.find(toFind)!=mpp.end() && toFind==30)
            {
                count+=mpp[toFind]-1;
            }
        }
        count+=(1ll)*(mpp[0]-1)*(mpp[0])/2;
        return count;
    }
};