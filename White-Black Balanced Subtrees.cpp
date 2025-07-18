#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N = 4001;
vector<ll> graph[N];
vector<ll> subtree_black(N,0), subtree_white(N,0);

void dfs(ll ver, ll par, string& s) {
    if(s[ver-1] == 'W') subtree_white[ver]++;
    else subtree_black[ver]++;
    for(auto& child : graph[ver]) {
        if(child == par) continue;
        dfs(child,ver,s);
        subtree_black[ver] += subtree_black[child];
        subtree_white[ver] += subtree_white[child];
    }
}

void reset() {
    for(ll i=0; i<N; i++) graph[i].clear();
    for(ll i=0; i<N; i++) subtree_black[i] = 0;
    for(ll i=0; i<N; i++) subtree_white[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        reset();
        ll n;
        cin >> n;
        for(ll i=2; i<=n; i++) {
            ll v;
            cin >> v;
            graph[i].push_back(v);
            graph[v].push_back(i);
        }
        string s;
        cin >> s;
        dfs(1,-1,s);
        ll ans = 0;
        for(ll i=1; i<=n; i++) {
            if(subtree_black[i] == subtree_white[i]) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}