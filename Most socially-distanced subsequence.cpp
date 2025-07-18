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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        //see for any a,b,c if (a < b && b < c) so |a-b| + |b-c| = |a-c| so it is always optimal to choose a,c rather than choosing a,b,c
        //and we can always pick up first and last element as they will always increase answer by some factor
        vector<ll> ans;
        ans.push_back(arr[0]);
        for(ll i=1; i<n-1; i++) {
            if((arr[i-1] < arr[i]) != (arr[i] < arr[i+1])) {
                ans.push_back(arr[i]);
            }
        }
        ans.push_back(arr[n-1]);
        cout << ans.size() << "\n";
        for(auto& v : ans) cout << v << " "; cout << "\n";
    }
    return 0;
}