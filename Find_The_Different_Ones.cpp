#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        vector<ll> changes;
        for(ll i=1; i<n; i++) {
            if(arr[i] != arr[i-1]) changes.push_back(i+1);
        }
        ll q;
        cin >> q;
        while(q--) {
            ll l,r;
            cin >> l >> r;
            ll ind = upper_bound(whole(changes), l) - changes.begin();
            ll i = -1, j = -1;
            if(ind < changes.size() && changes[ind] <= r) {
                i = l;
                j = changes[ind];
            }
            cout << i << " " << j << "\n";
        } 
        cout << "\n";
    }
    return 0;
}