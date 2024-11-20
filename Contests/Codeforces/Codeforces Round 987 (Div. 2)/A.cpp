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
        int n, f[51]; cin >> n;
        memset(f, 0, sizeof(f));
        vi vec(n);

        for(auto& x : vec) cin >> x;

        int equals = 0;
        for (int i = 0; i < n; i++) f[vec[i]]++;
        for (int i = 0; i <= n; i++) equals = max(equals, f[i]);
        
        cout << n - equals << '\n';
    }
    

    return 0;
}