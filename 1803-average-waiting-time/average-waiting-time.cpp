class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        double wait =customers[0][1];
        int curr = customers[0][0] + customers[0][1];
        for(int i=1;i<n;i++){
            wait += max(0,curr-customers[i][0]) + customers[i][1];
            curr = max(curr,customers[i][0]) + customers[i][1];
        }
        cout<<wait<<endl;

        return wait/n;
    }
};