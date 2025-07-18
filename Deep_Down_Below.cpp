#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

bool isPossible(ll x, vector<pair<ll,ll>>& min_needed) {
    ll prev = 0;
    for(auto& it : min_needed) {
        if((x + prev) < it.first) {
            return false;
        }
        prev += it.second;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<pair<ll,ll>> min_needed;
        while(n--) {
            ll k;
            cin >> k;
            ll dup = k;
            ll i = 0;
            ll curr_needed = 0;
            while(k--) {
                ll a;
                cin >> a;
                curr_needed = max(curr_needed, (a+1)-i);
                i++;
            }
            min_needed.push_back({curr_needed,dup});
        }
        sort(whole(min_needed));
        n = min_needed.size();
        //fffffttttt
        ll lo = min_needed[0].first;
        ll hi = min_needed[n-1].first;
        while((hi - lo) > 1) {
            ll mid = lo + (hi - lo)/2;
            if(isPossible(mid, min_needed)) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        if(isPossible(lo,min_needed)) cout << lo << "\n";
        else cout << hi << "\n";
    }
    return 0;
}