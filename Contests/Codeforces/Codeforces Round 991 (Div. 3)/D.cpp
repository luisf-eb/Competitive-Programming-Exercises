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
        string s;
        cin >> s;

        for (int i = 1; i < s.size(); i++) {
            int x = s[i] - '0';
            int j = i;
            while (j > 0 && x - 1 > s[j-1] - '0') {
                swap(s[j], s[j-1]);
                x--;
                s[j-1] = '0' + x;
                j--;
            }
        }
        
        cout << s << "\n";
    }
    

    return 0;
}