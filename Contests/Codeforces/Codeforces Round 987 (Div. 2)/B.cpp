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
    while (tc--) {
        int n; cin >> n;
        
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if(abs(x-i) > 1) flag = 0;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}