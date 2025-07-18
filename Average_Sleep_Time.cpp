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

const float eps = 1.00000000;
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        vector<ll> pfsum(n);
        pfsum[0] = arr[0];
        for(ll i=1; i<n; i++) pfsum[i] = pfsum[i-1] + arr[i];
        ll sum = pfsum[k-1];
        for(ll i=1; i<n-k+1; i++) {
            sum += (pfsum[i+k-1] - pfsum[i-1]);
        }
        ll weeks = n - k + 1;
        double ans = 1.0*sum/weeks;
        cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}