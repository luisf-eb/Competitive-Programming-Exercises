#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int tiles[31], memo[32][32][10010];
ll factorial[32];
int n, m, t;

ll getFactorial(int n, int k) {
    memset(factorial, 0, sizeof factorial);
    factorial[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            factorial[j] = factorial[j] + factorial[j - 1];
        }
    }
    return factorial[k];
}

int dp(int item, int qtd, int v) {
    if(v == 0 && qtd == 0) return 1;
    if(item == n || qtd == 0 || v < 0) return 0;
    int &x = memo[item][qtd][v];
    if(x != -1) return x;
    return x = dp(item + 1, qtd - 1, v - tiles[item]) + dp(item + 1, qtd, v);
}

int main() { fastio;

    int tc; cin >> tc;
    int cs = 1;

    while (tc--) {
        cin >> n;

        memset(tiles, 0, sizeof tiles);
        memset(memo, -1, sizeof memo);
        
        for (int i = 0; i < n; i++) cin >> tiles[i];

        cin >> m >> t;
        int ans = dp(0, m, t);

        ll notPossible = getFactorial(n, m) - ans;

        cout << "Game " << cs++ << " -- " << ans << " : " << notPossible << "\n";
    }
        

    return 0;
}