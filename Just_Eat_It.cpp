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
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        ll sum = 0;
        for(ll i=0; i<n; i++) sum += arr[i];
        ll best = MINF, curr = 0;
        for(ll i=0; i<n-1; i++) {
            curr = max(curr + arr[i], arr[i]);
            best = max(best, curr);
        }
        curr = 0;
        for(ll i=1; i<n; i++) {
            curr = max(curr + arr[i], arr[i]);
            best = max(best, curr);
        }
        if(sum > best) yes;
        else no;
    }
    return 0;
}