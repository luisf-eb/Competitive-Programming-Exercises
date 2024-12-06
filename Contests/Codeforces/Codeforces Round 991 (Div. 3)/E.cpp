#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string a, b, c;
vector<vector<int>> memo;

int dp(int i, int j) {
    if (i == 0 && j == 0) return 0;

    int &ans = memo[i][j];
    if (ans != -1) return ans;

    ans = INT_MAX;

    if (i > 0) {
        int cost = (c[i + j - 1] != a[i - 1]);
        ans = min(ans, dp(i - 1, j) + cost);
    }

    if (j > 0) {
        int cost = (c[i + j - 1] != b[j - 1]);
        ans = min(ans, dp(i, j - 1) + cost);
    }

    return ans;
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        int n = a.size(), m = b.size();

        memo.assign(n + 1, vector<int>(m + 1, -1));


        int ans = dp(n, m);
        cout << ans << "\n";
    }

    return 0;
}
