#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n, m; cin >> n >> m;
    vector<ll> cans(n), colors(m);

    for(auto &x : cans) cin >> x;
    for(auto &x : colors) cin >> x;

    sort(cans.begin(), cans.end());

    ll ans = 0;
    for(auto& x : colors) {
        auto it = lower_bound(cans.begin(), cans.end(), x);
         
        ans += *it - x;
    }

    cout << ans << "\n";

    return 0;
}