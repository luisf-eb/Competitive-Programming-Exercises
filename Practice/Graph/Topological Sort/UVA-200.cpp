#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<char> ans;
unordered_map<char, vector<char>> m;
vector<int> visited(26, 0);

void dfs(char u) {
    visited[u - 'A'] = 1;
    for (auto &v : m[u]) {
        if(!visited[v-'A'])
            dfs(v);
    }
    ans.push_back(u);
}

int32_t main() { fastio;
    string entrada;
    vector<string> entradas;

    while (cin >> entrada){
        if (entrada != "#")
            entradas.push_back(entrada); 
        if (entrada == "#"){
            int sz = entradas.size();
            for (int i = 0; i < sz-1; i++) {
                string s1 = entradas[i];
                string s2 = entradas[i+1];
                
                for (int j = 0; j < min(s1.size(), s2.size()); j++) {
                    if (s1[j] == s2[j]) continue;
                    else {
                        m[s1[j]].push_back(s2[j]);
                        break;
                    }
                }
            }

            if (m.find(entradas[0][0]) != m.end())
                dfs(entradas[0][0]);

            reverse(ans.begin(), ans.end());
    
            for(auto &x : ans) cout << x;
            cout << '\n';

            visited.assign(26,0);
            entradas.clear();
            ans.clear();
            m.clear();
        }
    }

return 0;
}