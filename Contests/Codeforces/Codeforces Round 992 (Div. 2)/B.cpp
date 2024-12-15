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
        int n; cin >> n;
        vi vec(n, 0);

        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }

        int ans = 1;
        for (int i = min(n, 4);; i = min((i+1) * 2, n)) {
            ans++;
            if(i == n) break;
        }
        
        cout << ans << "\n";
    }

    return 0;
}
