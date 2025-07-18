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
        ll n,w;
        cin >> n >> w;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        sort(whole(arr), greater<ll>());
        ll h = 1;
        multiset<ll> rem;
        rem.insert(w - arr[0]);
        for(ll i=1; i<n; i++) {
            auto it = rem.lower_bound(arr[i]);
            if(it == rem.end()) {
                h++;
                rem.insert(w - arr[i]);
            }else {
                rem.erase(it);
                rem.insert(*it - arr[i]);
            }
        }
        cout << h << '\n';
    }
    return 0;
}