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
        ll k,x;
        cin >> k >> x;
        ll for_all = k*k;
        if(x >= for_all) cout << (2*k - 1) << "\n";
        else {
            ll first_half = k*(k+1)/2, second_half = k*(k-1)/2;
            if(x <= first_half) {
                //we have to find in upper half
                ll lo = 1, hi = k;
                while((hi - lo) > 1) {
                    ll mid = lo + (hi - lo)/2;
                    ll curr = mid*(mid+1)/2;
                    if(curr >= x) {
                        hi = mid;
                    }else {
                        lo = mid + 1;
                    }
                }
                if(lo*(lo+1)/2 < x) cout << hi << "\n";
                else cout << lo << "\n";
            }else {
                //we have to find in lower half
                ll prev = k*(k+1)/2;
                x -= prev;
                ll lo = 1, hi = k-1;
                while((hi - lo) > 1) {
                    ll mid = lo + (hi - lo)/2;
                    ll curr = k*(k-1)/2 - mid*(mid-1)/2;
                    if(curr >= x) {
                        lo = mid;
                    }else {
                        hi = mid-1;
                    }
                }
                if((k*(k-1)/2 - hi*(hi-1)/2) < x) cout << k + (k-lo) << "\n";
                else cout << k + (k-hi) << "\n";
            }
        }
    }
    return 0;
}

