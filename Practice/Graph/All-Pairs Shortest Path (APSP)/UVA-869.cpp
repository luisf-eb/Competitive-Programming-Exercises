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
        int n, AM[26][26] = {0}, AM2[26][26] = {0};

        cin >> n;
        while (n--) {
            char u, v;
            cin >> u >> v;
            AM[u - 'A'][v - 'A'] = 1;
        }

        cin >> n;
        while (n--) {
            char u, v;
            cin >> u >> v;
            AM2[u - 'A'][v - 'A'] = 1;
        }
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    AM[i][j] |= (AM[i][k] & AM[k][j]);
                    AM2[i][j] |= (AM2[i][k] & AM2[k][j]);
                }
            }
        }

        bool valid = true;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if(AM[i][j] != AM2[i][j]) valid = false;
            }
        }
        
        if(valid) 
            cout << "YES\n";
        else
            cout << "NO\n";

        if(tc) cout << '\n';
    }
    
	return 0;
}