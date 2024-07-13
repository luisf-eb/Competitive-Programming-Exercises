#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main() { fastio;

    int nc, x, y, c = 1;
    while (cin >> nc && nc != 0) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        while (nc--) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            visited[x] = false; visited[y] = false;
        }
        
        while (cin >> x >> y) {
            if(x == 0 && y == 0) break;
            queue<pair<int, int>> q; q.push({x, y});
            unordered_map<int, bool> vTemp = visited;
            vTemp[x] = true;
            int nReacheble = 0;

            while (!q.empty()) {
                auto [u, ttl] = q.front(); q.pop();
                
                if(ttl > 0) {
                    for(auto& v : graph[u]) {
                        if(!vTemp[v]) {
                            vTemp[v] = true;
                            q.push({v, ttl-1});
                        }
                    }
                }
            }

            for(auto& [u, wasVisited] : vTemp) if(!wasVisited) nReacheble++;

            cout << "Case " << c++ << ": " << nReacheble << " nodes not reachable from node " << x << " with TTL = " << y << ".\n";
        }
        
    }
    

return 0;
}