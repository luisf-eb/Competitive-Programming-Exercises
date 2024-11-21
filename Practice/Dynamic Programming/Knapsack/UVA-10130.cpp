#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int p[1010], w[1010], memo[1010][31];

int main() { fastio;

    int tc; cin >> tc;
    while (tc--) {
        int n, ans = 0; cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> p[i] >> w[i];
        }
        
        int g; cin >> g;
        while (g--) {
            int W; cin >> W;
            memset(memo, 0, sizeof memo);

            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= W; j++) {
                    if(j - w[i] < 0) memo[i][j] = memo[i-1][j];
                    else memo[i][j] = max(memo[i-1][j], memo[i-1][j-w[i]] + p[i]);
                }
            }
            
            ans += memo[n][W];
        }

        cout << ans << "\n";
    }
       

    return 0;
}