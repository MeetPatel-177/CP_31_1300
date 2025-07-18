#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        ll ans = 0;
        for(ll i=30; i>=0; i--) {
            ll on = 0;
            for(ll j=0; j<n; j++) {
                if((a[j] >> i) & 1) on++;
            }
            ll off = n - on;
            if(k >= off) {
                ans |= (1 << i);
                k -= off;
            }
        }
        cout << ans << "\n";
    } 
    return 0;
}