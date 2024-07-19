#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

typedef pair<int, int> ii;

void dijkstras(int starting, vector<vector<ii>>& graph, vector<int>& dist) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[starting] = 0; pq.emplace(0, starting);

    while (!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if(d > dist[u]) continue;

        for(auto& [v, w] : graph[u]) {
            if(dist[u] + w >= dist[v]) continue;
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
        } 
    }
}

int main() { 
    fastio;

    int tests;
    cin >> tests;
    while (tests--) {
        int n, m, s, t, p;
        cin >> n >> m >> s >> t >> p;
        s--; t--;
        
        vector<vector<ii>> graph(n), graphT(n);
        vector<int> dist_fromS(n, INF), dist_fromT(n, INF);

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            graph[u].push_back({v, w});
            graphT[v].push_back({u, w});
        }

        dijkstras(s, graph, dist_fromS);
        dijkstras(t, graphT, dist_fromT);

        int ans = -1;
        for (int i = 0; i < n; i++) {
            for(auto& [u, w] : graph[i]) {
                if(dist_fromS[i] + dist_fromT[u] + w <= p) {
                    ans = max(ans, w);
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
