#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

vector<set<int>> graph;
vector<int> dfs_num, dfs_low, dfs_parent, r, p;
int dfsNumber;

int findSet(int i) {
    if (p[i] == i) return i;
    return p[i] = findSet(p[i]);
}

void unionSet(int i, int j) {
    if (findSet(i) == findSet(j)) return;
    int x = findSet(i), y = findSet(j);
    if (r[x] > r[y]) swap(x, y);
    p[x] = y;
    if (r[x] == r[y]) ++r[y];
}

void dfs(int u) {
    dfs_num[u] = dfsNumber++;
    dfs_low[u] = dfs_num[u];

    for (auto& v : graph[u]) {
        if(dfs_num[v] == -1) {
            dfs_parent[v] = u;
            dfs(v);

            if(dfs_low[v] > dfs_num[u]) {
                unionSet(u, v);
            }
            dfs_low[u] = min(dfs_low[v], dfs_low[u]); 
        }
        else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_num[v], dfs_low[u]);
        }
    }
}

int32_t main() { 
    fastio;
    int R, C, Q;
    while (cin >> R >> C >> Q && R != 0 && C != 0 && Q != 0) {
        dfs_num.assign(R, -1); dfs_low.assign(R, 0); dfs_parent.assign(R, -1); r.assign(R, 0); p.assign(R, 0);
        graph.assign(R, set<int>());
        dfsNumber = 0;
        
        for (int i = 0; i < R; i++) p[i] = i;
        
        while (C--) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            graph[x].insert(y);
            graph[y].insert(x);
        }

        for (int i = 0; i < R; i++) {
            if(dfs_num[i] == -1) dfs(i);
        }

        while (Q--) {
            int u, v;
            cin >> u >> v;
            u--; v--;

            if(findSet(u) == findSet(v)) cout << "Y\n";
            else cout << "N\n"; 
        }
        cout << "-\n";       
    }
    
    return 0;
}
