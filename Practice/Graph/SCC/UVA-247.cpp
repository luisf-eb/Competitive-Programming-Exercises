#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
unordered_map<string, int> visited;
vector<string> S, ans;


void dfs(string u, unordered_map<string, set<string>>& graph, int t) {
    visited[u] = 1;
    if(t) ans.push_back(u);
    for (auto& v : graph[u]) {
        if (!visited[v])
            dfs(v, graph, t);
    }
    S.push_back(u);
}

int32_t main() { fastio;
    int n, m;
    int cnt = 1;

    while (cin >> n >> m and m != 0 and n != 0) {
        if (cnt > 1) cout << '\n';
        unordered_map<string, set<string>> graph(n), graphT(n);
        unordered_map<string, int> visitedTemp(n);
        S.clear();

        while (m--) {
            string u, v;
            cin >> u >> v;
            graph[u].insert(v);
            graphT[v].insert(u);
            visitedTemp[u] = 0;
            visitedTemp[v] = 0;
        }

        visited = visitedTemp;
        for (auto& x : graph) if(!visited[x.first]) dfs(x.first, graph, 0);

        cout << "Calling circles for data set " << cnt++ << ":\n";
        visited = visitedTemp;
        for (int i = n-1; i >= 0; i--) {
            if(!visited[S[i]]) {
                ans.clear();
                dfs(S[i], graphT, 1);
                for (int j = 0; j < ans.size(); j++) {
                    if (j == ans.size()-1) cout << ans[j] << '\n';
                    else cout << ans[j] << ", ";
                }
            }
        }

    }
    

return 0;
}