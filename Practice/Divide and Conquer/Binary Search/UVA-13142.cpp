#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { 
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc, cs = 1; cin >> tc;

    while (tc--) {
        ll T, S, D; cin >> T >> S >> D;

        ll V = (D*1.0/T*1.0) * (1000000*1.0/86400*1.0);

        if(V > 0) cout << "Remove " << V << " tons\n";
        else cout << "Add " << abs(V) << " tons\n";
    }

    return 0;
}
