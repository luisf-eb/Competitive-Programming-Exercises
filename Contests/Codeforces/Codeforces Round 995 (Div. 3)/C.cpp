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

    int tc; cin >> tc;
    int freq[300010];
    while (tc--) {
        int n, m, k; cin >> n >> m >> k;
        vi vec(m), know(k);
        memset(freq, 0, sizeof freq);

        for(auto& x : vec) cin >> x;
        for(auto& x : know) { cin >> x; freq[x]++; }

        string ans = "";
        if(k == n) {
            for (int i = 0; i < m; i++) ans += '1';
            cout << ans << "\n";
            continue;
        }
        if(k < n-1) {
            for (int i = 0; i < m; i++) ans += '0';
            cout << ans << "\n";
            continue;
        }
        
        for (int i = 0; i < m; i++) {
            int x = vec[i];
            if(freq[x]) ans += '0';
            else ans += '1';
        }
        
        cout << ans << "\n";
    }
    

    return 0;
}