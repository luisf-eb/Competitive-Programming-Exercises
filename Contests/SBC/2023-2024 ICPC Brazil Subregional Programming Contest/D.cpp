#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int V, E;
    cin >> V >> E;
    vector<ii> queries;
    vector<vector<ii>> graph(V);

    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        queries.push_back({u, v});
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i < queries.size(); i++) {
        int s = queries[i].first, e = queries[i].second, ans = INF;
        vi dist(V, INF);
        dist[s] = 0;
        set<ii> pq;

        for (int u = 0; u < V; ++u)
            pq.emplace(dist[u], u);

        while (!pq.empty()) {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());

            if(u == e) { ans = d; break; }

            for (auto &[v, w] : graph[u]) {
                if(u == s && v == e) continue;
                if (dist[u] + w >= dist[v]) continue;

                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }

        if (ans != INF)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}