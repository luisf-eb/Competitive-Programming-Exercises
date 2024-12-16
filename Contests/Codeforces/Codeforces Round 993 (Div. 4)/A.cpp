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
        int n; cin >> n;
        
        int ans = 0;
        for (int b = 1; b <= n; b++) {
            for (int a = 1; a <= n; a++) {
                if(a == n - b) ans++;
            }
        }
        
        cout << ans << "\n";
    }
    

    return 0;
}