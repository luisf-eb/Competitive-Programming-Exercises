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

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        string s; cin >> s;

        int l = 0, r = n-1;
        if(s[l] == 's') l++;
        if(s[r] == 'p') r--;

        int a = 0, b = 0;
        while (l <= r) {
            if(s[l] == 'p' || s[r] == 'p') a |= 1;
            if(s[l] == 's' || s[r] == 's') b |= 1;
            l++; r--;
        }
        
        int flag = a & b;
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    

    return 0;
}