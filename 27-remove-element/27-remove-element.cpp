class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n = arr.size();
        int lptr = 0; int rptr = 0;
        while(rptr<n){
            if(arr[rptr]==val){
                rptr++; continue;
            }
            arr[lptr] = arr[rptr]; lptr++; rptr++;
        }
        return lptr;
    }
};