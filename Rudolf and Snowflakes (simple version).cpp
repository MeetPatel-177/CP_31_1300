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
vector<bool> poss(N,0);

void pre_compute() {
    for(ll i=2; i<N; i++) {
        for(ll j=i*i*i; (j-1)/(i-1)<N; j*=i) {
            poss[(j-1)/(i-1)] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre_compute();
    //k^m-1/k-1
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(poss[n]) yes;
        else no;
    }
    return 0;
}