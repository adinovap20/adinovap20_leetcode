typedef long long ll;
#define forl(i,a1,a2) for(i=a1;i<a2;i++)
#define forle(i,a1,a2) for(i=a1;i<=a2;i++)
#define nl "\n"
#define sp " "
#define deb(x); cout << #x << " = " << x << endl;
#define all(v) v.begin(),v.end()
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define F first
#define S second

class Solution {
public:
    int search(vector<int>& nums, int target) {
        ll n,i; n = nums.size();
        ll l = 0; ll r = n-1; ll res = -1;
        while(l<=r){
            ll m = l + (r-l)/2;
            if(nums[m]==target){
                return m;
            }
            if(nums[m]<target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return res;
    }
};