#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        string s; cin >> s;
        if(s.size() == i) ans++;
    }
    
    cout << ans << "\n";

    return 0;
}