class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        int a,req,j;
        for(int i=0;i<nums.size();i++){
            a = nums[i];
            req = target-a;
            for(j=i;j<nums.size();j++){
                if(i!=j && nums[j]==req){
                    output.push_back(i);
                    output.push_back(j);
                    break;
                }
            }
        }
        return output;
    }
};