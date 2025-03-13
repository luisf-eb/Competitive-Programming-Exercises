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

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m; cin >> n >> m;
        vector<string> vec(n);

        for(auto &x : vec) cin >> x;

        int ans = 0, sum = 0;;
        for (int i = 0; i < n; i++) {
            sum += vec[i].size();
            if(sum <= m) ans++;
            else break;
        }
        
        cout << ans << '\n';
    }
    

    return 0;
}