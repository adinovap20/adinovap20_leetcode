class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = target;
        vector<unsigned int> DP(n+1,0);
        DP[0] = 1;
        for(int i=1; i<=n; i++){
            DP[i] = 0;
            for(auto x : nums){
                if(i-x>=0){
                    DP[i] = DP[i] + DP[i-x];
                }
            }
        }
        return DP[n];
    }
};