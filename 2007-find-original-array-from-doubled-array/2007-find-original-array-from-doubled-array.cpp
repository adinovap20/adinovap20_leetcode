class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        int n = arr.size();
        if(n%2==1) return {};
        sort(arr.begin(),arr.end());
        unordered_map<int,int> m;
        for(auto x : arr){
            m[x]++;
        }
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            if(m[arr[i]]>=1){
                if(arr[i]%2==0){
                    if(m[arr[i]/2]>=1){
                        m[arr[i]/2]--;
                        ans.push_back(arr[i]/2);
                        m[arr[i]]--;
                    }else{
                        return {};
                    }
                }else{
                    return {};
                }
            }
        }
        return ans;
    }
};