class Solution {
public:

    int wateringPlants(vector<int>& plant, int c) {
        int n = plant.size();
        int cnt = 0;
        int cur = c;
        for(int i=0;i<n;i++){
            if(cur<plant[i]){
                cnt += 2*i + 1;
                cur=c-plant[i];
            }
            else{
                cnt++;
                cur-=plant[i];
            }
        }
        return cnt;
    }
};