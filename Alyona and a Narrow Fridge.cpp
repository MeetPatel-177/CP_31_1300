#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()
#define count_bits(x) 64 - __builtin_clzll(x);
#define set_bits(x) __builtin_popcountll(x);

#define yes cout << "YES\n"
#define no cout << "NO\n"

bool isPossible(ll k, vector<ll> a, ll h) {
    sort(a.begin(), a.begin()+k, greater<ll>());
    for(ll i=0; i<k; i+=2) {
        h -= a[i];
        if(h < 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,h;
        cin >> n >> h;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        ll lo = 2, hi = n;
        //tttttfffff
        while((hi - lo) > 1) {
            ll mid = lo + (hi - lo)/2;
            if(isPossible(mid,a,h)) {
                lo = mid;
            }else {
                hi = mid - 1;
            }
        }
        ll ans = -1;
        if(isPossible(hi,a,h)) ans = hi;
        else ans = lo;
        cout << ans << "\n";
    }
    return 0;
}