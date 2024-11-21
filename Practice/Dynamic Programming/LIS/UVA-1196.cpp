#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int n, memo[10010];
    while (cin >> n) {
        if(n == 0) { cout << "*\n"; break; }

        vector<ii> vec(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> vec[i].first >> vec[i].second;
        }
        
        sort(vec.begin(), vec.end());

        int ans = 0;
        memset(memo, 0, sizeof(memo));
        for (int i = 1; i <= n; i++) {
            int l = vec[i].first;
            int m = vec[i].second;
            for (int j = 0; j < i; j++) {
                int lj = vec[j].first;
                int mj = vec[j].second;
                if(lj <= l && mj <= m) {
                    memo[i] = max(memo[i], memo[j] + 1);
                    ans = max(ans, memo[i]);
                }
            }
        }

        cout << ans << "\n";
    }
    

    return 0;
}