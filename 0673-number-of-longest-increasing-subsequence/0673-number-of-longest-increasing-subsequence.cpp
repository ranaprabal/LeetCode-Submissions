class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size();
        vector<pair<int,int>>length(n);
        for(int i=0;i<n;i++){
            length[i].first=1;
            length[i].second=1;
        }
        pair<int,int>ans={0,0};
        for(int i=0;i<n;i++){
            int temp=1;
            int lmaxx=1;
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    if(lmaxx<=length[j].first){
                        temp=0;
                        lmaxx=length[j].first+1;
                        temp+=length[j].second;
                    }
                    else if(lmaxx==length[j].first+1){
                        temp+=length[j].second;
                    }
                }
            }
            length[i].first=lmaxx;
            length[i].second=temp;
            ans.first=max(ans.first,lmaxx);
        }
        for(int i=0;i<n;i++){
            if(ans.first==length[i].first) ans.second+=length[i].second;
        }

        return ans.second;
    }
};