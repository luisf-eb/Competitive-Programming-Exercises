#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void dfs(int u, vector<vector<int>>& graph, vector<int>& visited, vector<int>& S) {
    visited[u] = 1;
    for (auto& v : graph[u]) {
        if (!visited[v]) dfs(v, graph, visited, S);
    }
    S.push_back(u);
}

void dfsT(int u, vector<vector<int>>& graphT, vector<int>& component, int cg) {
    component[u] = cg;
    for (auto& v : graphT[u]) {
        if (!component[v]) dfsT(v, graphT, component, cg);
    }
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        vector<vector<int>> graphT(n);
        vector<int> visited(n, 0);
        vector<int> component(n, 0);
        vector<int> S;

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graphT[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i, graph, visited, S);
        }
        reverse(S.begin(), S.end());

        int cg = 0;
        for (int i = 0; i < n; i++) {
            if (!component[S[i]]) dfsT(S[i], graphT, component, ++cg);
        }

        vector<int> ins(cg+1, 0), outs(cg+1, 0);
        for (int i = 0; i < n; i++) {
            for (auto& v : graph[i]) {
                if (component[i] != component[v]) {
                    outs[component[i]]++;
                    ins[component[v]]++;
                }
            }
        }
        
        int out = 0, in = 0;
        for (int i = 1; i <= cg; i++) {
            if (!outs[i]) out++;
            if (!ins[i]) in++;
        }

        if (cg == 1) cout << 0 << '\n';
        else cout << max(out, in) << '\n';
    }

    return 0;
}
