#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            cnt++;
        }
        else {
            if(cnt > 1) ans += cnt;
            cnt = 0;
        }
    }
    
    if(cnt > 1) ans += cnt;

    cout << ans << "\n";

    return 0;
}