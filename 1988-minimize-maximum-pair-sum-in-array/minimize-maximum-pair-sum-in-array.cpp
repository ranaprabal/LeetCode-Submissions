class Solution {
public:
    int minPairSum(vector<int>& num) {
        sort(num.begin(),num.end());
        int sum = 0;
        int n = num.size();
        for(int i=0;i<n;i++){
            sum = max(sum,num[i]+num[n-1-i]);
        }
        return sum;
    }
};