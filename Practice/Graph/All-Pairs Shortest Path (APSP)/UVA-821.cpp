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

    string s;
    int t = 1;
	while (getline(cin, s) and s[0] != '0' and s[2] != '0') {
        stringstream ss(s);
        int AM[100][100], V = 0, u, w;

        memset(AM, INF, sizeof(AM));

        while (ss >> u >> w) {
            if (!u && !w) break;
            V = max(V, u);
            V = max(V, w);
            u--; w--;
            AM[u][w] = 1; 
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);
                }
            }
        }
        
        int total = 0, cnt = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(AM[i][j] != INF && i != j) {
                    total += AM[i][j];
                    ++cnt;
                }
            } 
        }
        
        double ans = 1.0*total / cnt;
        cout << "Case " << t++ << ": average length between pages = " << fixed << setprecision(3) << ans << " clicks\n";
    }
    
	return 0;
}