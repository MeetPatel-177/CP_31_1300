#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 998244353;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N = 2e5 + 1;
vector<ll> fact(N,0);

void pre_compute() {
    fact[0] = 1;
    for(ll i=1; i<N; i++) fact[i] = (fact[i-1] * i) % M;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre_compute();
    ll t = 1;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll n = s.size();
        ll mini = 0;
        ll ans = 1;
        ll i = 1;
        while(i < n) {
            ll curr = 0;
            while(i < n && s[i] == s[i-1]) {
                curr++;
                mini++;
                i++;
            }
            //we are choosing curr from (curr+1) ie curr+1Ccurr = (curr+1)
            ans = (ans * (curr+1)) % M;
            ++i;
        }
        //now we have all in our hands and total is mini and we have to permute it
        ans = (ans * fact[mini]) % M;
        cout << mini << " " << ans << "\n";
        //2c1 * 3c2 * mini!
    }
    return 0;
}