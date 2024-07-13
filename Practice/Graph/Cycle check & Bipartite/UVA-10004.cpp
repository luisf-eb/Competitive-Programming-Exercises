#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int32_t main() {fastio
    int n, l, x, y;
    while (cin >> n and n != 0) {
        cin >> l;
        vector<vector<int>> graph(n);
        while (l--) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        queue<int> q; q.push(0);
        vector<int> color(n, -1); color[0] = 0;
        bool bicolored = true;

        while(!q.empty() and bicolored) {
            int u = q.front(); q.pop();
            for (auto& v : graph[u]) {
                if (color[v] == -1) {
                    q.push(v);
                    color[v] = 1 - color[u]; 
                }
                if (color[v] == color[u]) {
                    bicolored = 0;
                    break;
                }
            }
        }

        if (bicolored) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    
    return 0;
}
