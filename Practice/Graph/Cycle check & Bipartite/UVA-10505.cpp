#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int32_t main() {
    fastio;
    int m, n, p, x;
    cin >> m;
    while (m--) {
        cin >> n;
        vector<set<int>> graph(210);
        for (int i = 0; i < n; i++) {
            cin >> p;
            while (p--) {
                cin >> x;
                x--;
                graph[i].insert(x);
                graph[x].insert(i);      
            }
        }
        
        vector<int> color(n, 0);
        int total = 0;

        for (int i = 0; i < n; i++) {
            if(!color[i]) {
                queue<int> q;
                q.push(i);
                color[i] = 1; // red
                    
                int red = 0; int black = 0;
                bool isBipartite = true;

                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    if (u < n) (color[u] == 1) ? red++ : black++;

                    for (auto& v : graph[u]) {
                        if(!color[v]) {
                            color[v] = (color[u] == 1) ? 2 : 1;
                            q.push(v);
                        } else if (color[u] == color[v]) {
                            isBipartite = false;
                        }
                    }
                }
                while (!q.empty()) q.pop();                
                
                if (isBipartite) total += max(red, black);
            }
        }
        cout << total << '\n';
    }

    return 0;
}
