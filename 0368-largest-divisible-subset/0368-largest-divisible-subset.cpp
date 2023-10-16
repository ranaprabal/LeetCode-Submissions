class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>count(n),prev(n);
        for(int i=0;i<n;i++){
            count[i]=1;
            prev[i]=i;
            for(int j=0;j<i;j++){
                int temp=j;
                bool p=(nums[i]%nums[temp]==0 || nums[temp]%nums[i]==0);
                if(p){
                    count[i]=max(count[i],count[j]+1);
                    if(count[i]==count[j]+1){
                        prev[i]=j;
                    }
                }
            }
        }
        int maxxInd = 0;
	    for(int i=0;i<n;i++){
		    if(count[i]>count[maxxInd]) maxxInd =i; 
	    }
        vector<int>ans;
	    while(maxxInd!=prev[maxxInd]){
		    ans.push_back(nums[maxxInd]);
		    maxxInd = prev[maxxInd];
	    }
	    ans.push_back(nums[maxxInd]);
	    // for(auto &it:ans) cout<<it<<" ";
	    reverse(ans.begin(),ans.end());
	    return ans;
    }
};