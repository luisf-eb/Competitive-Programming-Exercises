#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vi mono(n), stereo(n);

        for(auto& x : mono) cin >> x;
        for(auto& x : stereo) cin >> x;

        int ans = mono[n-1];

        for (int i = n-2; i >= 0; i--) {
            if(mono[i] > stereo[i+1]) ans += mono[i] - stereo[i+1];
        }

        cout << ans << "\n";
        
    }
    

    return 0;
}