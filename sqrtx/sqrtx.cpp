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
    int mySqrt(int x) {
        ll l = 1; ll r = sqrt(x)+1; ll res = 0;
        while(l<=r){
            ll m = l + (r-l)/2;
            if(m*m<=x){
                l = m+1;
                res = m;
            }else{
                r = m-1;
            }
        }
        return res;
    }
};