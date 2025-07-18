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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll n = s.size();
        ll i = 0;
        while(i < n) {
            char ch = s[i];
            char poss;
            if(ch == 'z') poss = 'a';
            else poss = (char)(s[i] + 1);
            ll curr = 0;
            while(i < n && s[i] == ch) {
                curr++;
                if(curr % 2 == 0) s[i] = poss;
                i++;
            }
            if(i < n && i > 0 && s[i] == s[i-1]) {
                if(s[i] == 'z') s[i-1] = 'a';
                else s[i-1] = (char)(s[i] + 1);
            }
        }
        cout << s << "\n";
    }
    return 0;
}