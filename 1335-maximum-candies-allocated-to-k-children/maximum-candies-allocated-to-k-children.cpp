class Solution {
public:

    bool pred(long long mid, vector<int>&candies,long long k){
        long long count = 0;
        for(auto &it:candies){
            count +=it/mid;
        }
        return count>=k;
    }


    int maximumCandies(vector<int>& candies, long long k) {
        long long sum= 0;
        for(auto &it:candies){
            sum+=it;
        }
        long long l = 0,r = sum+1;
        while(l+1<r){
            long long mid = l + (r-l)/2;
            if(pred(mid,candies,k)==0){
                r=mid;
            } else l =mid;
        }
        return (int)l;
    }
};