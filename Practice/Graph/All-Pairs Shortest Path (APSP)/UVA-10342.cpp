#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int to, length;
};

struct State {
    int node, dist;
    bool operator>(const State &other) const {
        return dist > other.dist;
    }
};

const int INF = INT_MAX;

void dijkstra(int n, int start, vector<vector<Edge>> &adj, vector<int> &dist, vector<int> &second_dist) {
    priority_queue<State, vector<State>, greater<State>> pq;
    dist.assign(n, INF);
    second_dist.assign(n, INF);
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > second_dist[u]) continue;

        for (auto &[v, len] : adj[u]) {
            int new_dist = d + len;
            if (new_dist < dist[v]) {
                swap(new_dist, dist[v]);
                pq.push({v, dist[v]});
            }
            if (new_dist > dist[v] && new_dist < second_dist[v]) {
                second_dist[v] = new_dist;
                pq.push({v, second_dist[v]});
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif


    int n, r, set_num = 1;
    while (cin >> n >> r) {
        vector<vector<Edge>> adj(n);
        for (int i = 0; i < r; ++i) {
            int u, v, l;
            cin >> u >> v >> l;
            adj[u].push_back({v, l});
            adj[v].push_back({u, l});
        }

        int q;
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].first >> queries[i].second;
        }

        vector<int> dist, second_dist;

        cout << "Set #" << set_num++ << '\n';
        for (auto &[u, v] : queries) {
            dijkstra(n, u, adj, dist, second_dist);
            if (second_dist[v] == INF) {
                cout << "?\n";
            } else {
                cout << second_dist[v] << '\n';
            }
        }
        
    }

    return 0;
}
