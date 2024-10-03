#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

vector<ll> ans;

void dfs(vector<vector<pair<ll, ll>>>& graph, vi& visited, int u, ll x) {
    visited[u] = 1;
    ans[u] = x;


    for(auto& [v, w] : graph[u]) {
        if(!visited[v]) dfs(graph, visited, v, ans[u] + w);
    }
}

int main() { fastio;

    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n);
    ans.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, -w});
    }

    vi visited(n, 0);
    
    for (int i = 0; i < n; i++) {
        if(!visited[i]) dfs(graph, visited, i, 0);
    }
    
    for(auto& elem : ans) cout << elem << " ";
    cout << '\n';

    return 0;
}