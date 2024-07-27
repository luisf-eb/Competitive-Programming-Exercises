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

    int p, r, nt = 1;
    while (cin >> p >> r) {
        if(!p && !r) break;

        unordered_map<string, int> relation;
        int AM[p][p];

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                AM[i][j] = INF;
            }
            AM[i][i] = 0;
        }
        
        int idx = 0;
        while (r--) {
            string u, v;
            cin >> u >> v;
            if(relation.find(u) == relation.end()) {
                relation[u] = idx++;
            }
            if(relation.find(v) == relation.end()) {
                relation[v] = idx++;
            }

            AM[relation[u]][relation[v]] = 1;
            AM[relation[v]][relation[u]] = 1;
        }
        
        for (int k = 0; k < p; k++) {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }
        
        int maxi = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++){
                if(AM[i][j] == INF) {
                    maxi = -1; 
                    break;
                }
                else maxi = max(maxi, AM[i][j]);
            }
        }
        

        if (maxi == -1) cout << "Network " << nt++ << ": DISCONNECTED\n";
        else cout << "Network " << nt++ << ": " << maxi << '\n';
        cout << '\n';
    }
    
    
	return 0;
}