#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int total;
vector<int> visited;

void dfs(int i, vector<vector<int>>& graph) {
    visited[i] = 1;
    total++;

    for(auto& x : graph[i]) {
        if(!visited[x]) {
            dfs(x, graph);
        }
    }
}


int main() {
    fastio;
    
    int t, n, m, l, x, y;
    cin >> t;

    while (t--) {
        cin >> n >> m >> l;
        vector<vector<int>> graph(n);
        visited.assign(n, 0);
        total = 0;
        while (m--){
            cin >> x >> y;
            graph[x-1].push_back(y-1);
        }
        
        while (l--) {
            cin >> x;
            if (!visited[x-1]) dfs(x-1, graph);
        }

        
        cout << total << '\n';
    }
    
    
   
    return 0;
}
