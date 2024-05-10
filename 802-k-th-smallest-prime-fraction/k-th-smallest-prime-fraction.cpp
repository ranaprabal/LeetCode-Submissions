class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        set<pair<double,pair<int,int>>>temp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                temp.insert({(double)arr[i]/(double)arr[j],{i,j}});
            }
        }
        for(auto it:temp){
            k--;
            if(k==0) return {arr[it.second.first],arr[it.second.second]};
        }
        return {0,0};
        
    }
};