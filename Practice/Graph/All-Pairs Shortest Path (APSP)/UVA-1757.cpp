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
    fastio;

	int n, m;
    while (cin >> n >> m) {
        int AM[26][26];
        memset(AM, 0, sizeof(AM));

        for (int i = 0; i < 26; i++){
            AM[i][i] = 1;
        }
        

        while (n--) {
            char x, y;
            cin >> x >> y;

            AM[x - 'a'][y - 'a'] = 1;
        }
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    AM[i][j] |= (AM[i][k] && AM[k][j]);
                }
            }
        }
        
        while (m--) {


            string a, b;
            cin >> a >> b;

            if(a.size() != b.size()) {
                cout << "no\n";
                continue;
            }

            int flag = 1;
            for (int i = 0; i < a.size(); i++) {
                int x = a[i] - 'a';
                int y = b[i] - 'a';

                if(!AM[x][y]) flag = 0; 
            }
            
            if(flag) cout << "yes\n";
            else cout << "no\n";
        }
        
    }
    
    

    
    
	return 0;
}