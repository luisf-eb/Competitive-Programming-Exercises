#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

vector<set<int>> graph;
vector<int> dfs_num, dfs_low, dfs_parent;
set<pair<int, int>> links;
int dfsNumber;

void dfs(int u) {
    dfs_num[u] = dfsNumber++;
    dfs_low[u] = dfs_num[u];

    for (auto& v : graph[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            
            dfs(v);

            if (dfs_low[v] > dfs_num[u]) {
                if (u < v) links.insert({u, v});
                else links.insert({v, u});
            }
            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
        }
        else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_num[v], dfs_low[u]);
        }
    }
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) 
        return a.first > b.first;
    else
        return a.second > b.second;
}

int32_t main() { 
    fastio;
    int n, m;
    while (cin >> n >> m && n!=0 && m!=0){
        dfs_low.assign(n, 0); dfs_num.assign(n, -1); dfs_parent.assign(n, -1);
        graph.assign(n, set<int>());
        links.clear();
        dfsNumber = 0;

        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        

        for (int i = 0; i < n; i++) if(dfs_num[i] == -1) dfs(i);
        
        vector<pair<int, int>> ans(links.begin(), links.end());
        sort(ans.begin(), ans.end());

        cout << links.size();
        for (auto& x : links) cout << " " << x.first << " " << x.second;
        cout << '\n';

    }
    
    return 0;
}
