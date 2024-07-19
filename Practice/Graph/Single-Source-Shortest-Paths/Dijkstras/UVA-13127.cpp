#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F

using namespace std;

int main() { 
    fastio;
    
    int n, m, b, p;
    while (cin >> n >> m >> b >> p) {
        vector<vector<pair<int, int>>> graph(n);
        vector<int> finalDist(n, -1), isBank(n, 0), isPolice;

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        int x;
        while (b--) {  
            cin >> x;
            isBank[x] = 1;
            finalDist[x] = INF;
        }
        
        while (p--) {
            cin >> x;
            isPolice.push_back(x);
        }
        
        vector<int> dist(n, INF);
        set<pair<int, int>> pq;

        for(auto& police : isPolice) {
            dist[police] = 0;
        }

        for (int i = 0; i < n; i++) {
            pq.emplace(dist[i], i);
        }
        
        while (!pq.empty()) {
            auto[d, u] = *pq.begin();
            pq.erase(pq.begin());

            if(isBank[u]) finalDist[u] = min(finalDist[u], d);

            for(auto& [v, w] : graph[u]) {
                if(dist[v] <= dist[u] + w) continue;
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
        

        int furthest = *max_element(finalDist.begin(), finalDist.end());
        vector<int> answers;
        for (int u = 0; u < n; u++) {
            if(finalDist[u] == furthest) answers.push_back(u);
        }
        
        int sz = answers.size();
        if(furthest == INF) cout << sz << " *\n";
        else cout << sz << " " << furthest << '\n';

        for (int i = 0; i < sz; i++) {
            if(i == sz-1) cout << answers[i] << '\n';
            else cout << answers[i] << " ";
        }
        
    }
    

    return 0;
}
