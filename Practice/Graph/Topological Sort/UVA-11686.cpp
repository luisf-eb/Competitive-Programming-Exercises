#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<int> ans;
vector<int> visited;
int control;
void dfs(int u, vector<vector<int>>& graph, vector<int>& cycleCheck) {
    visited[u] = 1;
    
    cycleCheck[u] = 1;
    for(auto& v : graph[u]) {
        if (cycleCheck[v]) {
            control = 1;
            return;
        }
        if(!visited[v]) {
            dfs(v, graph, cycleCheck);
        }
    }
    cycleCheck[u] = 0;
    ans.push_back(u);
}

int32_t main() { fastio;
    int n, m, x, y;
    while (cin >> n >> m and n != 0 and m != 0) {
        vector<vector<int>> graph(n+1);
        vector<int> CycleCheck(n+1, 0);
        visited.assign(n+1, 0);
        ans.clear();

        while (m--) {
            cin >> x >> y;
            graph[x].push_back(y);
        }

        control = 0;
        for (size_t i = 1; i <= n; i++) {
            if(!visited[i])
                dfs(i, graph, CycleCheck);
        }
        
        if (control) cout << "IMPOSSIBLE" << '\n';
        else {
            reverse(ans.begin(), ans.end());
            for (auto& x : ans) cout << x << '\n';
        }
        
    }
    
         

return 0;
}