#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

int main() { 
    fastio;

    int n, m, q, s, count = 0;
    while (cin >> n >> m >> q >> s) {
        if(n == 0 && m == 0 && q == 0 && s == 0) break;
        if(count++) cout << '\n';

        vector<vector<pair<int, int>>> graph(n);

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        
        vector<int> dist(n, INF); dist[s] = 0;
        set<pair<int, int>> pq;
        for (int u = 0; u < n; ++u) {
            pq.emplace(dist[u], u);
        }

        while (!pq.empty()) {
            auto[d, u] = *pq.begin(); pq.erase(pq.begin());

            for(auto& [v, w] : graph[u]) {
                if(dist[u]+w >= dist[v]) continue;
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u]+w;
                pq.emplace(dist[v], v);
            }
        }

        while (q--) {
            int i;
            cin >> i;
            if(dist[i] != INF) cout << dist[i] << '\n';
            else cout << "Impossible\n";
        }
        
    }   
    

    return 0;
}
