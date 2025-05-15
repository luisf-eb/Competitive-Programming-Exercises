#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

ll memo[90][2], h;

ll dp(int i, int prev) {
    if(i == h) return 1;

    ll &ans = memo[i][prev];
    if(ans != -1) return ans;

    ans = 0;
    if(prev)
        ans = dp(i+1, 1) + dp(i+1, 0);
    else 
        ans = dp(i+1, 1);

    return ans;
}

int main() { fastio;

    while (cin >> h && h) {
        memset(memo, -1, sizeof memo);
        ll ans = dp(1, 0);
        cout << ans << "\n";
    }
        

    return 0;
}