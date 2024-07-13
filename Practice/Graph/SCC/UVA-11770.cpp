#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<vector<int>> graph;
vector<int> visited, S;

void dfs(int u) {
    visited[u] = 1;
    for (auto & v : graph[u]) {
        if (!visited[v]) dfs(v);
    }
    S.push_back(u);
}

int32_t main() { 
    fastio;
    
    int t, n, m, cases = 1;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        S.clear();
        graph.assign(n, vector<int>()); 
        int ans = 0;
        
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
        }

        visited.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i);
        }

        visited.assign(n, 0);
        for (int i = n-1; i >= 0; i--) {
            if (!visited[S[i]]) {
                ans++;
                dfs(S[i]);
            }
        }
        cout << "Case " << cases++ << ": " << ans << '\n';
    }

    return 0;
}
