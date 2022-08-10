class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> DP(amount+1, 1E18);
        DP[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto x : coins){
                if(i-x>=0){
                    DP[i] = min(DP[i-x]+1, DP[i]);
                }
            }
        }
        if(DP[amount]==1E18){
            return -1;
        }
        return DP[amount];
    }
};