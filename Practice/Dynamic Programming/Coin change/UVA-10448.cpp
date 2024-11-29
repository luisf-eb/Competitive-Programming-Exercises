#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

vector<vector<ii>> graph;
vi costs, visited;

int dfs(int u, int e, int &c) {
    if(u == e) return 1;
    
    visited[u] = 1;
    int flag = 0;

    for(auto& [v, w] : graph[u]) {
        if(!visited[v]) {
            flag = dfs(v, e, c);
            if(flag) {
                costs.push_back(w);
                c -= w;
                return 1;
            }
        }
    }

    return 0;
}

int main() { 
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        graph.assign(n, vector<ii>());

        while (m--) {
            int x, y, w; 
            cin >> x >> y >> w;
            x--, y--;
            graph[x].push_back({y, w});
            graph[y].push_back({x, w});
        }
        
        int q; cin >> q;
        while (q--) {
            int s, e, c; 
            cin >> s >> e >> c;
            s--, e--;

            costs.clear();
            visited.assign(n, 0);
            int flag = dfs(s, e, c); 

            if(!flag || costs.empty()) {
                cout << "No\n";
                continue;
            }

            if(c == 0) {
                cout << "Yes " << costs.size() << "\n";
                continue;
            }

            if(c < 0 || c & 1) {
                cout << "No" << '\n';
                continue;
            }

            c /= 2;
            vi memo(c+1, INF);
            memo[0] = 0;

            for (int i = 1; i <= c; i++) {
                for(int j = 1; j < costs.size(); j++) {
                    int cost = costs[j];
                    if(i >= cost) {
                        memo[i] = min(memo[i], memo[i-cost] + 1);
                    }
                }
            }

            if(memo[c] < INF) {
                cout << "Yes " << costs.size() + memo[c]*2 << '\n';
            } else {
                cout << "No\n";
            }
            
        }
        if(tc) cout << '\n';
    }
    return 0;
}
