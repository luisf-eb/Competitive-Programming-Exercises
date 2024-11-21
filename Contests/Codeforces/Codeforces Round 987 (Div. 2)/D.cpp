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
        int n; cin >> n;
        vi vec(n), pf(n), sf(n), ans(n);
        for(auto& x : vec) cin >> x;

        pf[0] = vec[0];
        for (int i = 1; i < n; i++) pf[i] = max(pf[i-1], vec[i]);

        sf[n-1] = vec[n-1];
        for (int i = n-2; i >= 0; i--) sf[i] = min(sf[i+1], vec[i]);

        ans[n-1] = pf[n-1];
        for (int i = n-2; i >= 0; i--) {
            if(pf[i] > sf[i+1]) ans[i] = ans[i+1];
            else ans[i] = pf[i];
        }
        
        for(auto &x : ans) cout << x << " ";
        cout << '\n';
    }

    return 0;
}