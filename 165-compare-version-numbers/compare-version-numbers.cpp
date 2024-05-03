class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<long long> v1,v2;
        long long temp = 0;
        long long pow=1;
        for(long long i=version1.size()-1;i>=0;i--){
            if(version1[i]=='.'){
                v1.push_back(temp);
                pow=1;
                temp=0;
                continue;
            }
            temp = temp + pow*(version1[i]-'0');
            pow*=10;
            if(pow>INT_MAX) pow=1e9;
        }
        v1.push_back(temp);
        temp = 0;
        pow=1;
        for(long long i=version2.size()-1;i>=0;i--){
            if(version2[i]=='.'){
                v2.push_back(temp);
                pow=1;
                temp=0;
                continue;
            }
            temp = temp + pow*(version2[i]-'0');
            pow*=10;
            if(pow>INT_MAX) pow=1e9;
        }
        v2.push_back(temp);
        
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        long long n = v1.size();
        long long m = v2.size();
        // for(long long i=0;i<n;i++) cout<<v1[i]<<" ";
        // cout<<endl;
        // for(long long i=0;i<m;i++) cout<<v2[i]<<" ";
        long long i=0;
        for(i=0;i<min(n,m);i++){
            if(v1[i]<v2[i]) return -1;
            else if(v2[i]<v1[i]) return 1;
        }
        if(i==n){
            for(i;i<m;i++){
                cout<<v2[i];
                if(v2[i]) return -1;
            }
        }
        else if(i==m){
            for(i;i<n;i++){
                if(v1[i]) return 1;
            }
        }
        return 0;
    }
};