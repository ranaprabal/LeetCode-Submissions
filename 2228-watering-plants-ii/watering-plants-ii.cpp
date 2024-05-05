class Solution {
public:
    int minimumRefill(vector<int>& plant, int capacityA, int capacityB) {
        int n = plant.size();
        if(n<=2) return 0;
        int i=0,j=n-1,ans=0;
        int curA=capacityA,curB=capacityB;
        while(i<=j){
            if(i==j){
                if(curA>=plant[i] || curB>=plant[i]) break;
            }
            if(curA>=plant[i]){
                curA-=plant[i];
                i++;
            }
            else{
                ans++;
                curA=capacityA-plant[i];
                i++;
            }
            if(i>j) break;
            if(curB>=plant[j]){
                curB-=plant[j];
                j--;
            }else{
                ans++;
                curB=capacityB-plant[j];
                j--;
            }
            cout<<"index :";
            cout<<i<<" "<<j<<endl;
            cout<<curA<<" "<<curB<<endl;
        }
        return ans;
    }
};