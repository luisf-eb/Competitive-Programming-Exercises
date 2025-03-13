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
    
    int tc;
    cin >> tc;

    while (tc--) {
        string s; cin >> s;

        string ans = "";

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if(c == 'p') ans += 'q';
            if(c == 'q') ans += 'p';
            if(c == 'w') ans += 'w';
        }
        

        cout << ans << "\n";
    }   
    

    return 0;
}