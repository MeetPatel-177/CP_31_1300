#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N = 2e5 + 1;
map<ll,ll> freq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        freq.clear();
        ll n;
        cin >> n;
        vector<vector<ll>> arr;
        while(n--) {
            ll k;
            cin >> k;
            vector<ll> a;
            while(k--) {
                ll x;
                cin >> x;
                freq[x]++;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        bool found = 0;
        for(auto& it : arr) {
            bool curr = 1;
            for(auto& v : it) {
                if(freq[v] == 1) {
                    curr = 0;
                    break;
                }
            }
            if(curr) {
                found = 1;
                break;
            }
        }
        if(found) yes;
        else no;
    }
    return 0;
}