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
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        //for choosing k horizontal steps we can choose it in (k+1) ways
        //0 left, k right 
        //1 left, k-1 right
        //...
        //k left, 0 right total (k+1) ways
        if(n & 1) {
            ll k = n/2;
            cout << 2*(k+1)*(k+2) << "\n";
        }else {
            ll k = n/2;
            cout << (k+1)*(k+1) << '\n';
        }
    }
    return 0;
}