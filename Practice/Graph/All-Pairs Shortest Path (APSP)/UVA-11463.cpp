#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() {

	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

	int tc, cnt = 1;
	cin >> tc;

	while(tc--){
		int n, r;
        cin >> n >> r;

        int AM[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                AM[i][j] = INF;
            }
            AM[i][i] = 0;
        }
        
        while (r--) {
            int u, v;
            cin >> u >> v;
            AM[u][v] = 1;
            AM[v][u] = 1;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        int s, e, ans = 0; 
        cin >> s >> e;
        for (int i = 0; i < n; i++) {
            ans = max(ans, AM[s][i] + AM[i][e]);
        }
       
        
        cout << "Case " << cnt++ << ": " << ans << '\n';
	}
	return 0;
}