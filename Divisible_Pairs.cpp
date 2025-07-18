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
        ll n,x,y;
        cin >> n >> x >> y;
        map<ll,vector<ll>> mpp;
        for(ll i=0; i<n; i++) {
            ll a;
            cin >> a;
            mpp[a%y].push_back(a%x);
        }
        ll ans = 0;
        for(auto& it : mpp) {
            map<ll,ll> rem;
            vector<ll> curr = it.second;
            for(auto& a : curr) rem[a%x]++;
            for(auto& r : rem) {
                if(r.first == 0) ans += (r.second*(r.second-1))/2;
                else if(2*r.first == x) ans += (r.second*(r.second-1))/2;
                else if(2*r.first < x && rem.find(x-r.first) != rem.end()) {
                    ll a = r.second, b = rem[x-r.first];
                    ans += (a*b);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}