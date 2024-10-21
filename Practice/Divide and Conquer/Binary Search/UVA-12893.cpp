#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int solve(ll n) {
    if(n == 0) return 0;

    int ans = solve(n/2) + (n%2);
    return ans;
}

int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    int tc; cin >> tc;
    ll n;

    while (tc--) {
        cin >> n;

        cout << solve(n) << '\n';
    }
    

    return 0;
}