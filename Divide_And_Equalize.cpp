#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N = 1e6 + 1;
vector<ll> hp(N,-1);

void pre_compute() {
    for(ll i=2; i<=N; i++) {
        if(hp[i] == -1) {
            for(ll j=i; j<=N; j+=i) {
                hp[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre_compute();
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        //distribute all prime divisors equally
        //find count of all prime divisors first and then if any one prime divisor is not a multiple of n then we cannot distribute it into n size array so in order to distribute all prime factors with all value we have to have all it.second is a multiple of n 
        map<ll,ll> prime_divs;
        for(ll i=0; i<n; i++) {
            ll num = arr[i];
            while(num > 1) {
                ll p = hp[num];
                while(num % p == 0) {
                    prime_divs[p]++;
                    num /= p;
                }
            }
        }
        bool ans = 1;
        for(auto& it : prime_divs) {
            if(it.second % n != 0) {
                ans = 0;
                break;
            }
        }
        if(ans) yes;
        else no;
    }
    return 0;
}