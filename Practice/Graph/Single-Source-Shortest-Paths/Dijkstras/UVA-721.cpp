#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>


int dijkstras(int s, vector<vector<ii>>& graph) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vi dist(graph.size(), INF);
    dist[s] = 0; pq.emplace(dist[s], s);
    int total = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if(d > dist[u]) continue;
        total += d;
        for (auto& [v, w] : graph[u]) {
            if(dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
        }
    }
    
    return total;
}

void solve() {
    int p, q;
    cin >> p >> q;
    vector<vector<ii>> graph(p), graphT(p+1);

    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        if(u == v) continue;
        if(v == 0) {
            graphT[p].push_back({u, w});
        }
        else if (u != 0) {
            graphT[v].push_back({u, w});
        }

        graph[u].push_back({v, w});
    }
    
    int ansGoing = dijkstras(0, graph);
    int ansReturning = dijkstras(p, graphT);

    cout << ansGoing + ansReturning << '\n';
}

int main() {

	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

	int tc;
	cin >> tc;

	while(tc--){
        solve();
	}
	return 0;
}