/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

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
    int guessNumber(int n) {
        ll l = 1; ll r = n;
        while(l<=r){
            ll m = l + (r-l)/2;
            if(guess(m)==-1){
                r = m-1;
            }else if(guess(m)==1){
                l = m+1;
            }else{
                return m;
            }
        }
        return 0;
    }
};