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

   
    int p, r, bh, of, yh, markt;

    while (cin >> p >> r >> bh >> of >> yh >> markt) {
        bh--; of--; yh--; markt--;

        int AM[p][p], AM2[p][p], used[p];

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                AM[i][j] = AM2[i][j] = INF;
            }
            AM[i][i] = AM2[i][i] = 0;
            used[i] = 0;
        }
        

        while (r--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            AM[u][v] = w;
            AM[v][u] = w;
            AM2[u][v] = w;
            AM2[v][u] = w;
        }
        
        for (int k = 0; k < p; k++) {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        for (int i = 0; i < p; i++) {
            if(AM[bh][of] == AM[bh][i] + AM[i][of]) {
                used[i] = 1;
            }
        }
        
        for (int k = 0; k < p; k++) {
            if(used[k]) continue;
            for (int i = 0; i < p; i++) {
                if(used[i]) continue;
                for (int j = 0; j < p; j++) {
                    if(used[j]) continue;
                    AM2[i][j] = min(AM2[i][j], AM2[i][k] + AM2[k][j]);
                }
            }
        }

        int ans = AM2[yh][markt];
        if(ans != INF && !used[yh] && !used[markt])
            cout << ans << '\n';
        else
            cout << "MISSION IMPOSSIBLE.\n";
    }
    
    
	return 0;
}