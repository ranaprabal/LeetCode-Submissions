class Solution {
public:
    map<pair<int,int>,int>mpp;
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        if(mpp.find({m,n})!=mpp.end()) return mpp[{m,n}];
        return mpp[{m,n}] = uniquePaths(m-1,n)+uniquePaths(m,n-1); 
    }
};