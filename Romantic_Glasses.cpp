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
        //whenever we are dealing with alternate sum type things just put negative sign for all even indices and then take simple sum and solve the problem
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        map<ll,ll> mpp;
        mpp[0] = 1;
        ll sum = 0;
        bool found = 0;
        for(ll i=0; i<n; i++) {
            if(i & 1) arr[i] = -arr[i];
            sum += arr[i];
            if(mpp[sum]) {
                found = 1;
                cout << "YES\n";
                break;
            }
            mpp[sum] = 1;
        }
        if(!found) cout << "NO\n";
    }
    return 0;
}