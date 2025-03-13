#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>


int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vi vec(n);
        for (int& x : vec) cin >> x;

        bool flag = false;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            bool canWin = true;
            for (int j = 0; j < n; j++) {
                if (i != j && abs(vec[i] - vec[j]) % k == 0) {
                    canWin = false;
                    break;
                }
            }
            if (canWin) {
                flag = true;
                ans = i + 1;
                break;
            }
        }

        if (flag) {
            cout << "YES\n" << ans << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
