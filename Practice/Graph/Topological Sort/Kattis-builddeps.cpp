#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<string> ans;
unordered_map<string, bool> visited;
unordered_map<string, vector<string>> dag;

void dfs (string u) {
    visited[u] = true;

    for(auto& x : dag[u]) {
        if(!visited[x])
            dfs(x);
    }

    ans.push_back(u);
}

int32_t main() { fastio;

    string filename, line, s;
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        getline(cin, line);
        stringstream ss(line);
        ss >> s;
        s.pop_back();
        visited[s] = false;
        while (ss >> filename) {
            dag[filename].push_back(s);
        }
    }    

    cin >> filename;
    dfs(filename);
    reverse(ans.begin(), ans.end());

    for(auto& x : ans) {
        cout << x << '\n';
    }


return 0;
}