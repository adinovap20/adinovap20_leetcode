class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x : nums) m[x]++;
        for(int i=1; i<=1E5+1; i++){
            if(m[i]==0){
                return i;
            }
        }
        return 0;
    }
};