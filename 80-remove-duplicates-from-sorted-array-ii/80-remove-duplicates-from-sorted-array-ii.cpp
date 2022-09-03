class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int cur = INT_MIN; int cnt = 0; int n = arr.size();
        int lptr = 0; int rptr = 0;
        while(rptr<n){
            if(arr[rptr]!=cur){
                arr[lptr] = arr[rptr];
                cur = arr[rptr];
                lptr++;
                cnt = 1;
                rptr++;
                continue;
            }
            if(arr[rptr]==cur && cnt==1){
                arr[lptr] = arr[rptr];
                cur = arr[rptr];
                lptr++;
                cnt++;
                rptr++;
                continue;
            }
            cnt = 0;
            rptr++;
        }
        return lptr;
    }
};