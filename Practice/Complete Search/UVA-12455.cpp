#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int tc; cin >> tc;

    while(tc--) {
        int n, p; cin >> n >> p;
        vi v(p);
        for (int i = 0; i < p; i++) cin >> v[i];

        int flag = 0;

        for (int i = 0; i < (1<<p); i++) {
            int sum = 0;
            
            for (int j = 0; j < p; j++) {
                if(i & (1<<j)) sum += v[j];
                if(sum == n) {
                    flag = 1;
                    cout << "YES\n";
                    break;
                }
            }
            
            if(flag) break;
        }

        if(!flag) cout << "NO\n";
        
    }

    return 0;
}