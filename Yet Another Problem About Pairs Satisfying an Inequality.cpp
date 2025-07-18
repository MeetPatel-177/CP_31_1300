#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

ll values(ll n, vector<ll>& poss_value) {
    ll ind = upper_bound(whole(poss_value),n) - poss_value.begin();
    return (poss_value.size() - ind);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        vector<ll> poss, poss_value;
        for(ll i=0; i<n; i++) {
            if(arr[i] < (i+1)) {
                poss.push_back(i+1);
                poss_value.push_back(arr[i]);
            }
        }        
        sort(whole(poss_value));
        ll ans = 0;
        for(auto& it : poss) {
            ans += values(it, poss_value);
        }
        cout << ans << '\n';
    }
    return 0;
}