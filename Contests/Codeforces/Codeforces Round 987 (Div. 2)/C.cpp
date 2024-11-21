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
    while (tc--) {
        int n; cin >> n;

        if(n%2) {
            if(n < 27) {
                cout << -1 << '\n';
                continue;
            }

            vi ans = {1, 3, 3, 4, 4, 5, 5, 6, 6, 1, 2, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 1, 2};
            for (int i = 14; i*2 <= n; i++){
                ans.push_back(i);
                ans.push_back(i);
            }
            
            for (int i = 0; i < n; i++) {
                if(i == n-1) cout << ans[i] << '\n';
                else cout << ans[i] << '\n';
            }
        }
        else {
            vi ans;
            for (int i = 1; i*2 <= n; i++){
                ans.push_back(i);
                ans.push_back(i);
            }
            
            for (int i = 0; i < n; i++) {
                if(i == n-1) cout << ans[i] << '\n';
                else cout << ans[i] << ' ';
            }
        }
    }
        

    return 0;
}