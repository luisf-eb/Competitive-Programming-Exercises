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
        int n, a, b, c; cin >> n >> a >> b >> c;

        int ans = (n/(a+b+c))*3;
        int aux = n%(a+b+c);

        while (aux > 0) {
            aux -= a;
            ans++;
            if(aux <= 0) break;
            aux -= b;
            ans++;
            if(aux <= 0) break;
            aux -= c;
            ans++;
            if(aux <= 0) break;
        }
        
        cout << ans << "\n";
    }
    

    return 0;
}