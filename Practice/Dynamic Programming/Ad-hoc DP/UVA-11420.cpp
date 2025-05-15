#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

ll memo[66][66][2];

ll dp(int n, int s, int prev) {
    if(n == 0) return s == 0;

    ll &ans = memo[n][s][prev];
    if(ans != -1) return ans;

    if(prev) ans = dp(n-1, s, 0) + dp(n-1, s, 1);
    else ans = dp(n-1, s-1, 0) + dp(n-1, s, 1);

    return ans;
}

int main() { fastio;

    int n, s;
    while (cin >> n >> s) {
        if(n < 0 && s < 0) break;

        memset(memo, -1, sizeof memo);

        ll ans = dp(n, s, 0);
        cout << ans << "\n";
    }
    

    return 0;
}