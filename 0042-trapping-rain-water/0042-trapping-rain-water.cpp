class Solution {
public:
    
    int trap(vector<int>& h) {
        int i=0,j=h.size()-1;
        int lhs=0,rhs=0,ans=0;
        while(i<j){
            lhs=max(lhs,h[i]);
            rhs=max(rhs,h[j]);
            ans+=(lhs<rhs)?lhs-h[i++]:rhs-h[j--];
        }
        return ans;
    }
};