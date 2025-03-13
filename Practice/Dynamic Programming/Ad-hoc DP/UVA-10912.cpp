#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int memo[27][500][27];

int dp(int L, int S, int k) {
    // cout << L  << ", " << S << ", " << k << '\n';
    if(L == 0) return S == 0;
    if(L > 26) return 0;

    int& ans = memo[L][S][k];
    if(ans != -1) return ans;

    ans = 0;
    for (int i = k; i < 27; i++) {
        if(S - i < 0) break; 
        ans += dp(L-1, S-i, i+1);
    } 
    return ans;
}

int main() { fastio;

    int tc = 1, L, S;
    while (cin >> L >> S && L && S) {
        memset(memo, -1, sizeof memo);

        if(L > 26 || S > 400) {
            cout << "Case " << tc++ << ": " << 0 << "\n";
            continue;
        }

        int ans = dp(L, S, 1);

        cout << "Case " << tc++ << ": " << ans << "\n";
    }
    

    return 0;
}