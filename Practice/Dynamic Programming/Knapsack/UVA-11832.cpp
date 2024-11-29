#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int N, F, pos[41], neg[41], memo[41][32010], val[41];

int dp(int x, int V) {
    int curr = V + 16000;
    if (x == N) return V == F ? 1 : 0;

    if (memo[x][curr] != -1) return memo[x][curr];

    int p = 0, n = 0;

    if (V + val[x] <= 16000)
        p = dp(x + 1, V + val[x]);
    if (V - val[x] >= -16000)
        n = dp(x + 1, V - val[x]);

    pos[x] |= p;
    neg[x] |= n;

    return memo[x][curr] = p | n;
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    while (cin >> N >> F) {
        if (N == 0 && F == 0) break;

        for (int i = 0; i < N; i++) cin >> val[i];

        memset(pos, 0, sizeof pos);
        memset(neg, 0, sizeof neg);
        memset(memo, -1, sizeof memo);

        int ans = dp(0, 0);

        if (!ans) {
            cout << "*\n";
        } else {
            for (int i = 0; i < N; i++) {
                if (pos[i] && neg[i]) cout << "?";
                else if (pos[i]) cout << "+";
                else if (neg[i]) cout << "-";
            }
            cout << "\n";
        }
    }

    return 0;
}
