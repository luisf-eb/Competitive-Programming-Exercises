#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
vector<vector<int>> graph;
vector<int> visited, S;


void dfs(int u) {
    visited[u] = 1;
    for (auto& v : graph[u]) {
        if(!visited[v]) dfs(v);
    }
    S.push_back(u);
}

int32_t main() { fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        graph.assign(n, vector<int>()); S.clear();

        while (m--) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
        }
        visited.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if(!visited[i]) dfs(i);
        }
        
        reverse(S.begin(), S.end());
        visited.assign(n, 0);
        int minDominos = 0;
        for (int i = 0; i < n; i++) {
            if(!visited[S[i]]) {
                minDominos++;
                dfs(S[i]);
            }
        }
        
        cout << minDominos << '\n';
    }
    
    
return 0;
}