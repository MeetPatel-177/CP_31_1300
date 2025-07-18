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

vector<ll> primes(ll n) {
    vector<ll> divs;
    while(n % 2 == 0) {
        divs.push_back(2);
        n /= 2;
    }
    for(ll i=3; i*i<=n; i+=2) {
        while(n % i == 0) {
            divs.push_back(i);
            n /= i;
        }
    }
    if(n > 1) divs.push_back(n);
    return divs;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> p_divs = primes(n);
        ll ff = p_divs[0];
        //number itself a prime number
        if(ff == n || p_divs.size() == 2) {no; continue;}
        ll ss = -1;
        if(p_divs[0] == p_divs[1]) ss = p_divs[1] * p_divs[2];
        else ss = p_divs[1];
        ll tt = n/(ff*ss);
        if(tt == ff || tt == ss || tt == 1) {no; continue;}
        yes;
        cout << ff << " " << ss << " " << tt << "\n";
    }
    return 0;
}