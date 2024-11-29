#include <bits/stdc++.h>
using namespace std;

/* TYPES */
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

    int n, m, p[101], memo[30001], q[1001], maxi = 0; cin >> n;
    memset(p, 0, sizeof p);
    memset(memo, 0, sizeof memo);
    memset(q, 0, sizeof q);

    for (int i = 0; i < n; i++) cin >> p[i];

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> q[i];
        maxi = max(maxi, q[i]);
    }
    
    vector<multiset<int>> sets(maxi);
    memo[0] = 1;
    for (int i = 1; i <= maxi; i++) {
        for (int j = 0; j < n; j++) {
            if(i - p[j] >= 0 && memo[i-p[j]] != 0) {
                if(memo[i] == 1) {
                    sets[i] = sets[i-p[j]];
                    sets[i].insert(p[j]);
                }
                else ++memo[i];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int x = q[i];
        if(memo[x] > 1) cout << "Ambiguous\n";
        else if(memo[x] == 0) cout << "Impossible\n";
        else {
            for(auto& elem : sets[x]) cout << elem << " ";
            cout << '\n';
        }
    }
    
    

    return 0;
}
