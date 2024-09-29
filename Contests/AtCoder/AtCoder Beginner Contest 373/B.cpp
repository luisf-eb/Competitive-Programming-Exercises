#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    string s; cin >> s;
    vi count(s.size());

    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'A';
        count[idx] = i;
    }
    

    int ans = 0;
    for (int i = 0; i < count.size() - 1; i++) {
        ans += abs(count[i+1] - count[i]);
    }
    
    cout << ans << "\n";

    return 0;
}