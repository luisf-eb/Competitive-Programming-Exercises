#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<string> grid;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s; grid.push_back(s);
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '#' && i != 0) cout << j+1 << ' ';
                if(grid[i][j] == '#' && i == 0) cout << j+1 << '\n';
            }
        }
    }
    

    return 0;
}