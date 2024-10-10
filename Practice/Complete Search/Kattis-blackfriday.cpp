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
    vi freq(7), participants(n);

    for(auto& x : participants) { cin >> x; ++freq[x]; }
    
    int ans = -1, highest = 0;
    for (int i = 0; i < n; i++) {
        int x = participants[i];
        if(freq[x] == 1 && x > highest) {
            highest = x;
            ans = i;
        }
    }
    
    if(ans == -1) cout << "none\n";
    else cout << ans+1 << '\n';

    return 0;
}