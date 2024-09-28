#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1e18
#define ll long long
#define ii pair<int, int>
#define iii tuple<long, int, int>
#define vi vector<int>

void Djikstras(vector<vector<pair<int, ll>>>& graph, vector<ll>& dist, vector<ll>& distH, bitset<300000>& hs, int s) {
    
    priority_queue<iii, vector<iii>, greater<iii>> pq;

    dist[s] = 0;
    pq.push({0, 0, s});

    while (!pq.empty()) {
        auto [d, h, u] = pq.top(); pq.pop();

        if (d > (h ? distH[u] : dist[u])) continue;

        bool horse = (h || hs[u]);

        vector<ll>& distTemp = h ? distH : dist;
        for (auto& [v, w] : graph[u]) {
            vector<ll>& distTempN = horse ? distH : dist;
            ll distancia = horse ? w / 2 : w;

            if (distTempN[v] <= distTemp[u] + distancia) continue;
            
            distTempN[v] = distTemp[u] + distancia;
            pq.push({distTempN[v], horse, v});
        }
    }
}

int main() {
    fastio;

    int cs;
    cin >> cs;

    while (cs--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<vector<pair<int, ll>>> graph(n);
        bitset<300000> bs;
        
        for (int i = 0; i < h; i++) {
            int horse;
            cin >> horse;
            bs[horse - 1] = 1;
        }

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<ll> distM(n, INF), distH(n, INF), distHorseM(n, INF), distHorseH(n, INF);

        ll ans = INF;

        Djikstras(graph, distM, distHorseM, bs, 0);
        Djikstras(graph, distH, distHorseH, bs, n - 1);

        for (int i = 0; i < n; i++) {
            distM[i] = min(distM[i], distHorseM[i]);
            distH[i] = min(distH[i], distHorseH[i]);

            ll a = max(distM[i], distH[i]);
            ans = min(ans, a);
        }

        if (ans == INF)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}
