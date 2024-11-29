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

    int n, m; cin >> n >> m;
    map<string, int> mp;

    while (n--) {
        string s; cin >> s;
        for (int i = 0; i < m; i++) {
            if(s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    s[i] = 'a' + j;
                    mp[s]++;
                }
            }
        }
    }
    
    string anss;
    int ans = 0;

    for(auto& [x, y] : mp) {
        if(y > ans) {
            anss = x;
            ans = y;
        }
    }

    cout << anss << " " << ans << "\n";

    return 0;
}