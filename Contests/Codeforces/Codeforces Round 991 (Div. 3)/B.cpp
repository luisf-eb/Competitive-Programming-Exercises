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

    int tc;
    cin >> tc;

    while (tc--) {
        int n; cin >> n;
        vi vec(n);

        for(auto& x : vec) cin >> x;

        ll flag = 0, sumP = 0, sumI = 0;
        ll elemP = 0, elemI = 0;
        for (int i = 0; i < n; i++) {
            if(i&1) {
                sumI += vec[i];
                elemI++;
            } else {
                sumP += vec[i];
                elemP++;
            }
        }
        
        if(sumP % elemP == 0 && sumI % elemI == 0 && sumP/elemP == sumI/elemI) flag = 1;

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}