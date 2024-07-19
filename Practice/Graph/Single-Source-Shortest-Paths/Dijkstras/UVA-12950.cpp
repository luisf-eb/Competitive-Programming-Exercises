#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    fastio;
    
    int c, m;
    while (cin >> c >> m) {
        vector<vector<pair<int, int>>> graph(c), evenGraph(c);
        vector<int> dist(c, INF);
        
        while (m--) {
            int u, j, w;
            cin >> u >> j >> w;
            u--; j--;

            graph[u].push_back({j, w});
            graph[j].push_back({u, w});
        }
        
        for (int i = 0; i < c; i++) {
            for(auto& [n, w1] : graph[i]) {
                for(auto& [nn, w2] : graph[n]) {
                    evenGraph[i].push_back({nn, w1+w2});
                }
            }
        }

        c--;
        set<pair<int, int>> pq;
        dist[0] = 0;
        
        for (int i = 0; i <= c; i++) {
            pq.emplace(dist[i], i);
        }

        while (!pq.empty()) {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());

            if(u == c) break;

            for(auto& [v, w] : evenGraph[u]) {
                if(dist[u] + w >= dist[v]) continue;
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v); 
            }
        }
        
        if(dist[c] == INF) cout << -1 << '\n';
        else cout << dist[c] << '\n';
    }
    
    

    return 0;
}