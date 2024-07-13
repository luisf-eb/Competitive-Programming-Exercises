#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

vector<set<int>> graph;
vector<int> dfs_num, dfs_low, dfs_parent, articulationPoints, visited;
vector<pair<int,int>> CC;
int dfsNumber, root, rootChildren, ccs;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first > b.first;
    } else {
        return a.second < b.second;
    }
}

void dfs2(int u) {
    visited[u] = 1;
    for (auto& v : graph[u]) {
        if(!visited[v]) dfs2(v);
    }
}

void dfs(int u) {
    dfs_num[u] = dfsNumber++;
    dfs_low[u] = dfs_num[u];

    for (auto& v : graph[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == root) rootChildren++;

            dfs(v);

            if (dfs_low[v] >= dfs_num[u]) articulationPoints[u] = 1;
            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
        }
        else if (dfs_parent[v] != u) {
            dfs_low[u] = min(dfs_num[v], dfs_low[u]);
        }
    }
}

int32_t main() { 
    fastio;
    int n, m;
    while (cin >> n >> m and n != 0 and m != 0){
        graph.assign(n, set<int>());
        dfs_num.assign(n, -1); dfs_low.assign(n, 0); dfs_parent.assign(n, -1);
        articulationPoints.assign(n, 0); CC.assign(n, pair<int, int>());
        dfsNumber = 0;

        int X, Y;
        while (cin >> X >> Y and X != -1 and Y != -1) {
            graph[X].insert(Y);
            graph[Y].insert(X);
        }
        
        for (int i = 0; i < n; i++) {
            if(dfs_num[i] == -1) {
                root = i; rootChildren = 0;
                dfs(root);
                articulationPoints[root] = (rootChildren > 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (articulationPoints[i]) {
                visited.assign(n, 0);
                visited[i] = 1;
                int ccs = 0;
                for (int j = 0; j < n; j++) {
                    if(!visited[j]){
                        ccs++;
                        dfs2(j);
                    }
                }
                CC.push_back({ccs, i});
            } else {
                CC.push_back({1, i});
            }
        }
        
        sort(CC.begin(), CC.end(), compare);
        
        for (int i = 0; i < m; i++) {
            cout << CC[i].second << " " << CC[i].first << '\n';
        }
        cout << '\n';
        
    }
    
    

    return 0;
}
