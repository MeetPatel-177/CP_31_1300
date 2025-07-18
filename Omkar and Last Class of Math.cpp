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

ll needed(ll n) {
    vector<ll> divs;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(i != n/i) divs.push_back(n/i);
        }
    }
    sort(whole(divs));
    return divs[divs.size() - 2];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n & 1) {
            ll need = needed(n);
            cout << need << " " << n - need << "\n";
        }else {
            cout << n/2 << " " << n/2 << "\n";
        }
    }
    return 0;
}