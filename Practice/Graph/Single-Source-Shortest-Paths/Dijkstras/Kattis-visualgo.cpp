#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

typedef pair<int, int> ii;

int main() { 
    fastio;
    
    int V, E, s, t;
    cin >> V >> E;

    vector<vector<ii>> graph(V);
    vector<int> dist(V, INF), paths(V, 0);

    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    cin >> s >> t;

    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(dist[s], s); paths[s] = 1;

    while (!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if(d > dist[u]) continue;

        for(auto& [v, w] : graph[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                paths[v] = paths[u];
            }
            else if(dist[v] == dist[u] + w) {
                paths[v] += paths[u];
            }
        }
    }
    
    cout << paths[t] << '\n';

    return 0;
}
