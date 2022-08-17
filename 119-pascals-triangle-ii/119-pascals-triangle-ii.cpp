typedef long long ll;

class Solution {
public:
    int nCr(int n, int r) {
        ll p = 1; ll k = 1;
        if(n-r < r){
            r = n - r;
        }
        if(r!=0){
            while(r){
                p *= n;
                k *= r;
                ll m = __gcd(p,k);
                p/=m;
                k/=m;
                n--; r--;
            }
        }else{
            p = 1;
        }
        return (int)p;
    }
    vector<int> getRow(int rowIndex) {
        int cur = 0;
        vector<int> ans;
        for(int i=0; i<=rowIndex; i++){
            ans.push_back(nCr(rowIndex, cur));
            cur++;
        }
        return ans;
    }
};