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
        int n, k; cin >> n >> k;
        string s; cin >> s;

        vector<ll> suf(n, 0);
        suf[n-1] = (s[n-1] == '1') ? 1 : -1;
        suf[0] = -INF;
        for (int i = n-2; i > 0; i--) {
            suf[i] = suf[i+1]; 
            if(s[i] == '0') suf[i]--;
            else suf[i]++; 
        }
        
        sort(suf.begin(), suf.end());
        ll ans = 1, sum = 0;
        int i = n-1;
        while (i > 0 && sum < k) {
            sum += suf[i];
            ans++;
            i--;
        }

        if(sum < k) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    

    return 0;
}