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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        for(ll i=0; i<n; i++) {
            ll lo = 0, hi = i;
            //see we will only take the current element if (arr[i]/pos >= 1)
            //so when we are at any i we will start iterating from i till any j for which we will not be able to take it
            //so the sequence would be like fffffttttt and we have to find the first t it will maximize the len for the current i
            //fffffttttt
            while((hi - lo) > 1) {
                ll mid = lo + (hi - lo)/2;
                if(arr[mid] >= (i - mid + 1)) {
                    hi = mid;
                }else {
                    lo = mid + 1;
                }
            }
            if(arr[lo] >= (i - lo + 1)) {
                cout << (i - lo + 1) << " ";
            }else {
                cout << (i - hi + 1) << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}