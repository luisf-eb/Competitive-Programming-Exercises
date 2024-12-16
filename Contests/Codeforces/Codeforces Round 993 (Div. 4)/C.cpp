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
        int m, a, b, c; cin >> m >> a >> b >> c;

        int rowA = min(m, a);
        int rowB = min(m, b);
        int resto = (m-rowA) + (m-rowB);

        int ans = rowA + rowB + min(c, resto);

        cout << ans << "\n";
    }   
    

    return 0;
}