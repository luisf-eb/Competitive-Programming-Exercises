#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main() { 
    fastio;
    
    int t;
    cin >> t;
    while (t--) {
        int n, l, x;
        cin >> n >> l;
        vector<vector<int>> graph(n);
        vector<int> frequency(n, 0), important(n, 0);
        vector<int> averages(n, INT_MAX);

        for (int i = 0; i < l; i++) {
            vector<int> line;
            while (cin >> x && x != 0) {
                x--;
                line.push_back(x);
            }
            for (int j = 1; j < line.size(); j++) {
                graph[line[j]].push_back(line[j-1]);
                graph[line[j-1]].push_back(line[j]);
            }
            for (int j = 0; j < line.size(); j++) {
                frequency[line[j]]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (frequency[i] > 1) 
                important[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (important[i]) {
                vector<int> distance(n, INT_MAX);
                queue<pair<int, int>> q;
                int distImportant = 0;
                q.push({i, 0});
                distance[i] = 0;

                while (!q.empty()) {
                    auto [u, d] = q.front(); q.pop();

                    if (important[u] && u != i) 
                        distImportant += d; 

                    for (auto &v : graph[u]) {
                        if (distance[v] == INT_MAX) {
                            distance[v] = d + 1;
                            q.push({v, d + 1});
                        }
                    }
                }
                
                averages[i] = distImportant;
            }
        }

        int minimum = INT_MAX;
        int ans;
        for (int i = 0; i < n; i++) {
            if (averages[i] < minimum) {
                minimum = averages[i];
                ans = i;
            }
        }
        
        cout << "Krochanska is in: " << ans + 1 << '\n';
    }

    return 0;
}
