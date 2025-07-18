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
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        ll sum = 0, maxi = 0, s_maxi = 0;
        for(ll i=0; i<n; i++) {
            sum += arr[i];
            if(arr[i] > maxi) {
                s_maxi = maxi;
                maxi = arr[i];
            }else if(arr[i] > s_maxi) {
                s_maxi = arr[i];
            } 
        }
        vector<ll> ans;
        for(ll i=0; i<n; i++) {
            ll curr_maxi = maxi;
            if(arr[i] == maxi) curr_maxi = s_maxi;
            ll curr_sum = sum - arr[i];
            if(2*curr_maxi == curr_sum) {
                ans.push_back(i+1);
            }
        }
        cout << ans.size() << "\n";
        for(auto& v : ans) cout << v << " "; cout << "\n";
    } 
    return 0;
}