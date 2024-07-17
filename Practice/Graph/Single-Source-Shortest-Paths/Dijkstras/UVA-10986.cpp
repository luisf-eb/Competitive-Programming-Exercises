#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

int main() { 
    fastio;
    
    int n, cases = 1;
    cin >> n;
    while (n--) {
        int V, m, S, T;
        cin >> V >> m >> S >> T;

        vector<vector<pair<int, int>>> graph(V);
        vector<int> dist(V, INF);

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        set<pair<int, int>> pq;
        dist[S] = 0;
        for (int i = 0; i < V; i++) {
            pq.emplace(dist[i], i);
        }
        
        while (!pq.empty()) {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            
            if(u == T) break;

            for(auto& [v, w] : graph[u]) {
                if(dist[u] + w >= dist[v]) continue;
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }

        cout << "Case #" << cases++ << ": ";
        if(dist[T] == INF) cout << "unreachable\n";
        else cout << dist[T] << '\n';
    }
    

    return 0;
}
