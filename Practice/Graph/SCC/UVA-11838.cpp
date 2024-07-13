#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
vector<vector<int>> graph, graphT;
vector<int> visited, S;

void dfs(int u, int pass) {
    visited[u] = 1;
    vector<int> AL = (pass == 1) ? graph[u] : graphT[u];
    for (auto& v : AL) {
        if(!visited[v]) dfs(v, pass);
    }
    S.push_back(u);
}

int32_t main() { fastio;

    int N, M;
    while (cin >> N >> M && N!=0 && M!=0){
        graph.assign(N, vector<int>()); S.clear(); graphT.assign(N, vector<int>());

        while (M--) {
            int u, v, p;
            cin >> u >> v >> p;
            u--; v--;

            if(p == 1) {
                graph[u].push_back(v);
                graphT[v].push_back(u);
            }
            else {
                graph[u].push_back(v);
                graph[v].push_back(u);
                graphT[u].push_back(v);
                graphT[v].push_back(u);
            }
        }

        visited.assign(N, 0);
        for (int i = 0; i < N; i++) {
            if(!visited[i]) {
                dfs(i, 1);
            }
        }
        
        visited.assign(N, 0);
        int numSCC = 0;
        for (int i = N-1; i >= 0; i--) {
            if(!visited[S[i]]) {
                numSCC++;
                dfs(S[i], 2);
            }
        }
        
        if (numSCC > 1) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    

return 0;
}