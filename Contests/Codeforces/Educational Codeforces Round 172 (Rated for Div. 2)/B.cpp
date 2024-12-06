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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi vec(n);
        unordered_map<int, int> f;
        
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
            f[vec[i]]++;
        }
        
        int single = 0, duo = 0;
        for(auto& [x, qtd] : f) {
            if(qtd == 1) single++;
            else if(qtd > 1) duo++;
        }
        
        int ans = 2*((single+1)/2) + duo;

        cout << ans << '\n';
    }
    return 0;
}