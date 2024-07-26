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
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

    int tc;
    cin >> tc;

    while (tc--) {
        int box, n, q;
        cin >> box >> n;

        int AM[n+1][n+1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                AM[i][j] = INF;
            }
            if(i != 0) {
                AM[i][i] = 0;
            }
        }

        cin >> q;
        while (q--) {
            int x; 
            cin >> x;
            AM[0][x] = 0;
        }

        for (int i = 1; i <= n; i++) {
            int x, cost;
            cin >> q;
            while (q--) {
                cin >> cost >> x;
                AM[i][x] = min(AM[i][x], cost);
            }   
        }
        
        for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);
                }
            }
        }

        int total = 0, ans = 0;
        while (true) {
            total += AM[0][0];
            if(total >= box) break;
            ans++;
            total--;
        }
        
        cout << ans << '\n';
    }
    
	return 0;
}