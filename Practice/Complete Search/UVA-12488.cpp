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

    int n;

    while (cin >> n) {
        vi inicial(n, -1), final(n, -1);
        int x, ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> x; x--;
            inicial[x] = i;
        }
        
        for (int i = 0; i < n; i++){
            cin >> x; x--;
            final[x] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int posInit = inicial[i], posEnd = final[i];
            for (int j = 0; j < n; j++){
                if(j == i) continue;
                if(inicial[j] < posInit && final[j] > posEnd) ans++;
            }
        }
        
        cout << ans << "\n";
    }
       

    return 0;
}