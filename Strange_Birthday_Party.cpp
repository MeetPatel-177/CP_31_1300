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
        ll n,m;
        cin >> n >> m;
        vector<ll> k(n), c(m);
        for(ll i=0; i<n; i++) cin >> k[i];
        for(ll i=0; i<m; i++) cin >> c[i];
        sort(whole(k), greater<ll>());
        ll cost = 0;
        ll curr = 0;
        for(ll i=0; i<n; i++) {
            if(c[curr] < c[k[i] - 1]) {
                cost += c[curr];
                curr++;
            }else {
                cost += c[k[i] - 1];
            }
        }
        cout << cost << '\n';
    }
    return 0;
}