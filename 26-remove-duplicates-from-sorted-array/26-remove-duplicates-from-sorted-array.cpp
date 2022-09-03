class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int cur = INT_MIN; int lptr = 0; int rptr = 0; int n = arr.size();
        while(rptr<n){
            if(arr[rptr]!=cur){
                arr[lptr]=arr[rptr];
                cur = arr[rptr];
                lptr++;
            }
            rptr++;
        }
        return lptr;
    }
};