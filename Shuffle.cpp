#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
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
    cin >> t;
    while(t--) {
        ll n,x,m;
        cin >> n >> x >> m;
        pair<ll,ll> range = {x,x};
        while(m--) {
            ll l,r;
            cin >> l >> r;
            if(r < range.first || l > range.second) {
                continue;
            }else {
                range = {min(range.first,l), max(range.second,r)};
            }
        }
        ll ans = range.second - range.first + 1;
        cout << ans << "\n";
    }
    return 0;
}