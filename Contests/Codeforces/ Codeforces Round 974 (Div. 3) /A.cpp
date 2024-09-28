#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;
    int cs; cin >> cs;

    while (cs--) {
        int n, k; cin >> n >> k;
        int robin = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x >= k) robin += x;
            else if(x == 0 && robin) {
                robin--;
                ans++;
            }
        }
        
        cout << ans << '\n';
    }
    
    

    return 0;
}