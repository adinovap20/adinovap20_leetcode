class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> suff(n); suff[n-1] = arr[n-1][1];
        for(int i=n-2; i>=0; i--){
            if(arr[i][1] > suff[i+1]){
                suff[i] = arr[i][1];
            }else{
                suff[i] = suff[i+1];
            }
        }
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            int l = i; int r = n-1; int res = -1;
            while(l<=r){
                int m = l + (r-l)/2;
                if(arr[m][0]>arr[i][0]){
                    r = m-1;
                    res = m;
                }else{
                    l = m+1;
                }
            }
            if(res==-1){
                break;
            }
            if(suff[res]>arr[i][1]){
                cnt++;
            }
        }
        return cnt;
    }
};