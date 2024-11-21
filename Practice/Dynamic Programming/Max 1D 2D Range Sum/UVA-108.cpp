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

    int n;
    int m[110][110];
    while(cin >> n) {
        memset(m, 0, sizeof(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
                if(j > 0) m[i][j] += m[i][j-1];
            }
        }
        
        int ans = -INF;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int subRect = 0;

                for (int row = 0; row < n; row++){
                    int aux;
                    if(l > 0) aux = m[row][r] - m[row][l];
                    else aux = m[row][r];

                    subRect += aux;
                    ans = max(ans, subRect);
                    if(subRect < 0) subRect = 0;
                }
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}