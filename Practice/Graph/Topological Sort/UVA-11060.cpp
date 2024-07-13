#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int32_t main() { fastio;
    int cases = 1;
    int n, m;
    string input;
    while (cin >> n) {
        vector<string> relation(n);
        vector<int> in_degree(n, 0);
        unordered_map<string, int> relationS;
        unordered_map<string, vector<string>> dag;
        for (int i = 0; i < n; i++) {
            cin >> input;
            relation[i] = input;
            relationS[input] = i;
        }
        
        cin >> m;
        while (m--) {
            string s1, s2;
            cin >> s1 >> s2;
            dag[s1].push_back(s2);
            in_degree[relationS[s2]]++;
        }
        
        // TOPOSORT
        vector<string> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int u = 0; u < n; u++) {
            if (in_degree[u] == 0) pq.push(u);
        }

        while (!pq.empty()) {
            int u = pq.top(); pq.pop();

            ans.push_back(relation[u]);

            for(auto& v : dag[relation[u]]) {
                in_degree[relationS[v]]--;
                if (in_degree[relationS[v]] == 0) {
                    pq.push(relationS[v]);
                }
            }
        }
        
        cout << "Case #" << cases++ << ": Dilbert should drink beverages in this order: ";
        for (int i = 0; i < n; i++) {
            if (i == n-1) cout << ans[i] << ".\n";
            else cout << ans[i] << " ";
        }
        cout << '\n';
        cin.ignore(); cin.ignore();
    }
         

return 0;
}