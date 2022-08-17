class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> DP(n, vector<int>(5));
        for(int i=0; i<5; i++){
            DP[0][i] = 1;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<5; j++){
                DP[i][j] = 0;
                for(int k=j; k<5; k++){
                    DP[i][j] += DP[i-1][k];
                }
            }
        }
        int ans = 0;
        for(int i=0; i<5; i++){
            ans = ans + DP[n-1][i];
        }
        return ans;
    }
};