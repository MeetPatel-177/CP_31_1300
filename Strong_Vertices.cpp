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
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<n; i++) cin >> b[i];
        vector<ll> diff(n);
        for(ll i=0; i<n; i++) {
            diff[i] = a[i] - b[i];
        }
        ll maxi = *max_element(whole(diff));
        vector<ll> ans;
        for(ll i=0; i<n; i++) {
            if(diff[i] == maxi) ans.push_back(i+1);
        }
        cout << ans.size() << "\n";
        for(auto& a : ans) cout << a << " "; cout << "\n";
    }
    return 0;
}