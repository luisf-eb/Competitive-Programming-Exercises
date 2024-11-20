#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n, h; cin >> n >> h;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x <= h) ans++;
    }
       
    cout << ans << '\n';

    return 0;
}