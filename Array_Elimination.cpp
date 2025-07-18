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
        //01101
        //00111
        //11001
        //10011
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        ll g = 0;
        for(ll i=0; i<30; i++) {
            ll set_bits = 0;
            for(ll j=0; j<n; j++) {
                if((arr[j] >> i) & 1) set_bits++;
            }
            g = __gcd(g,set_bits);
        }
        if(g == 0) {
            for(ll i=1; i<=n; i++) cout << i << ' ';
            cout << "\n";
        }else {
            vector<ll>divs;
            for(ll i=1; i*i<=g; i++)  {
                if(g % i == 0) {
                    divs.push_back(i);
                    if(g/i != i) divs.push_back(g/i);
                }
            }
            sort(whole(divs));
            for(auto& d : divs) cout << d << ' ';
            cout << '\n';
        }
    }
    return 0;
}