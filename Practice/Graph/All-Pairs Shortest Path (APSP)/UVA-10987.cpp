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
    
    int tc, cases = 1;
    cin >> tc;
    
    while (tc--){
        cout << "Case #" << cases++ << ":\n";
        int n; cin >> n;
        int AM[n+1][n+1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                AM[i][j] = 0;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                int w; cin >> w;
                AM[i+1][j] = w;
                AM[j][i+1] = w;
            }
        }

        int flag = 0;
        for (int k = 1; k <= n; k++){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++) {
                    if(min(AM[i][k], AM[k][j]) <= 0) continue;
                    if(AM[i][k] + AM[k][j] < AM[i][j]) flag = 1;
                    if(AM[i][k] + AM[k][j] == AM[i][j]) AM[i][j] = -1;
                }
            }
        }

        if(flag) {
            cout << "Need better measurements.\n";
            cout << "\n";
            continue;
        } 

        int cnt = 0;
        vector<tuple<int, int, int>> ans;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(AM[i][j] > 0) {
                    ans.push_back({i, j, AM[i][j]});
                    cnt++;
                    AM[j][i] = -1;
                }
            }   
        }
        
        cout << cnt << '\n';
        for (auto& [u, v, w] : ans) {
            cout << u << " " << v << " " << w << '\n';
        }

        cout << '\n';
    }
    
    
    
	return 0;
}