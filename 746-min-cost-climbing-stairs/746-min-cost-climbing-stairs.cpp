class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> DP(n+1);
        DP[0] = cost[0];
        DP[1] = cost[1];
        for(int i=2; i<cost.size(); i++){
            DP[i] = min(DP[i-2], DP[i-1]) + cost[i];
        }
        DP[n] = min(DP[n-1],DP[n-2]);
        return DP[n];
    }
};