#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int tc; cin >> tc;
    int f[7];

    while (tc--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;

        memset(f, 0, sizeof f);

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'A';
            f[idx]++;
        }
        
        int ans = 0;
        for (int i = 0; i < 7; i++) {
            if(m > f[i]) ans += m - f[i]; 
        }
        
        cout << ans << '\n';
    }
    

    return 0;
}