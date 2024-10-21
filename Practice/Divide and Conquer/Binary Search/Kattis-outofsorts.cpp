#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n, m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;

    vector<ll> seq(n+1);
    seq[0] = x0;

    for (int i = 1; i <= n; i++) seq[i] = (a*seq[i-1] + c) % m;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ll x = seq[i];
        int l = 1, r = n;

        while (l <= r) {
            int mid = (l + r) / 2;

            if(seq[mid] == x) { ++ans; break; }
            else if(seq[mid] > x) r = mid - 1;
            else if(seq[mid] < x) l = mid + 1;
        }
    }
    
    cout << ans << "\n";

    return 0;
}