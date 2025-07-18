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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(ll i=0; i<n; i++) {
            cin >> a[i];
            --a[i];
        }
        for(ll i=0; i<n; i++) {
            cin >> b[i];
            --b[i];
        }
        vector<ll> pos(n);
        for(ll i=0; i<n; i++) pos[b[i]] = i;
        //we are making time array (c) what will it store ?
        //the time at which the current car will go out of the tunnel
        //then when we encounter any thing which is smaller than all its previous then it means it must cross anyone in order to get ahead so it must be fined
        vector<ll> c(n);
        for(ll i=0; i<n; i++) c[i] = pos[a[i]];
        ll maxi = -1, ans = 0;
        for(ll i=0; i<n; i++) {
            if(c[i] < maxi) {
                ++ans;
            }else {
                maxi = c[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}