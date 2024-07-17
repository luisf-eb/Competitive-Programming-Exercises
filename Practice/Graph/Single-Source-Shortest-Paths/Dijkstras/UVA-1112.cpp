#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

int main() { 
    fastio;
    int t; 
    cin >> t;
    while (t--) {
        int n, m, timer, e;
        cin >> n >> e >> timer >> m;
        e--;

        vector<vector<pair<int, int>>> transpose(n);
        vector<int> dist(n, INF);
                
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            transpose[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[e] = 0; pq.push({0, e});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if(d > dist[u]) continue;
            for(auto& [v, w] : transpose[u]) {
                if(dist[v] <= dist[u]+w) continue;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
        
        int ans = 0;
        for(auto& x : dist) {
            if(x <= timer) ans++;
        }

        cout << ans << '\n';
        if(t > 0) cout << '\n';
    }
    

    return 0;
}
