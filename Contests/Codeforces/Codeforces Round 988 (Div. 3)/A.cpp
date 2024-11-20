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
    while (tc--){
        int n; cin >> n;
        int freq[50];
        memset(freq, 0, sizeof(freq));
        int ans = 0;
        while (n--) {
            int x; cin >> x;
            freq[x]++;
            if(freq[x] % 2 == 0) ans++;
        }
        cout << ans << "\n";
    }
    

    return 0;
}