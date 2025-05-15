#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

vi vec;
int n;

int memo[1001][1001];

int dp(int idx, int last_jump) {
    if (idx < 0 || idx >= n) return INF;
    if (idx == n - 1) return vec[n-1];
    
    int &ans = memo[idx][last_jump];
    if (ans != -1) return ans;
    
    int a = INF, b = INF;
    a = dp(idx + last_jump + 1, last_jump + 1) + vec[idx];
    b = dp(idx - last_jump, last_jump) + vec[idx];
    
    return ans = min(a, b);
}

int main() {
    fastio;

    cin >> n;
    vec.resize(n);

    for (auto &x : vec) cin >> x;

    memset(memo, -1, sizeof(memo));

    int ans = dp(1, 1);

    cout << ans << "\n";

    return 0;
}
