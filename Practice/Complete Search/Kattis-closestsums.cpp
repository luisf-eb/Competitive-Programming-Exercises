#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n, tc = 1;

    while(cin >> n) {
        vi vec(n);

        for(auto& x : vec) cin >> x;
        sort(vec.begin(), vec.end());

        int m; cin >> m;

        cout << "Case " << tc++ << ":\n";
        while (m--) {
            int x; cin >> x;
            
            int diff = INF, ans = 0;
            
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if(abs(vec[i] + vec[j] - x) < diff) {
                        diff = abs(vec[i] + vec[j] - x);
                        ans = vec[i] + vec[j];
                    }
                }
            }
                    
                
            cout << "Closest sum to " << x << " is " << ans << ".\n";
        }
        
    }

    return 0;
} 