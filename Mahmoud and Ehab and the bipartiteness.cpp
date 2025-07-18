#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()
#define count_bits(x) 64 - __builtin_clzll(x);
#define set_bits(x) __builtin_popcountll(x);

#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N = 1e5 + 1;
vector<ll> graph[N];
vector<ll> color(N,0);

void dfs(ll ver, ll par=-1) {
    for(auto& child : graph[ver]) {
        if(child == par) continue;
        color[child] = color[ver]^1^2;
        dfs(child,ver);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(ll i=0; i<n-1; i++) {
            ll v1,v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        //whenever the question is around coloring in 2 ways ie bipartiteness then always color all the nodes according to the rules of bipartiteness and then only solve the question most off time the logic will be around it only
        color[1] = 1;
        dfs(1);
        //we can make edges only in between the twos which are not having the same color so we can choose one from l and one from r but we already have n-1 edges so answer will be (l*r - (n-1))
        ll l = 0, r = 0;
        for(ll i=1; i<=n; i++) {
            if(color[i] == 1) l++;
            else r++;
        }
        cout << l*r - (n-1) << "\n";
    }
    return 0;
}