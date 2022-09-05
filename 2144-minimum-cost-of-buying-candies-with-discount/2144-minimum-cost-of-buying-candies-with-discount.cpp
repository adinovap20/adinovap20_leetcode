class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>()); int n = cost.size();
        int ans = 0; int i = 0;
        for(i=0; i<n-2; i+=3){
            ans = ans + cost[i] + cost[i+1];
        }
        while(i<n){
            ans = ans + cost[i++];
        }
        return ans;
    }
};