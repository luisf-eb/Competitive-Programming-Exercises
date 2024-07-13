#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

vector<set<int>> graph;
vector<int> dfs_num, dfs_low, dfs_parent, articulationPoints;
int dfsNumber, root, rootChildren;

void dfs(int u) {
    dfs_num[u] = dfsNumber++;
    dfs_low[u] = dfs_num[u];

    for (auto& v : graph[u]) {
        if(dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (root == u) rootChildren++;

            dfs(v);

            if(dfs_low[v] >= dfs_num[u]) articulationPoints[u] = 1;

            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
        } 
        else if (v != dfs_parent[u]) 
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int32_t main() { 
    fastio;
    int n;
    while (true) {
        cin >> n;
        if (!n) break;

        int ans = 0;
        graph.assign(n, set<int>()); 
        articulationPoints.assign(n, 0);
        dfs_num.assign(n, -1); 
        dfs_low.assign(n, 0); 
        dfs_parent.assign(n, -1);
        dfsNumber = 0;

        int V;
        string line;
        cin.ignore();
        while (getline(cin, line) && !line.empty()) {
            stringstream ss(line);
            ss >> V;
            if (V == 0) break;
            V--;
            int X;
            while(ss >> X) {
                X--;
                graph[V].insert(X);
                graph[X].insert(V);
            }
        }

        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == -1) {
                root = i; 
                rootChildren = 0;
                dfs(root);
                articulationPoints[root] = (rootChildren > 1);
            }
        }

        for (auto& x : articulationPoints) if (x) ans++;
        cout << ans << '\n';
    }

    return 0;
}
