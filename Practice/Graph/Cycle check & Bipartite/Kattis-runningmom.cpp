#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

unordered_map<string, vector<string>> graph;
int control;

void dfs(const string& u, unordered_map<string, int>& dfs_num) {
    dfs_num[u] = 1;
    for (const auto& v : graph[u]) {
        if (dfs_num[v] == 0) {
            dfs(v, dfs_num);
        } else if (dfs_num[v] == 1) {
            control = 1;
        }
    }
    dfs_num[u] = 2;
}

int32_t main() {
    fastio;
    int n;
    string s1, s2;
    cin >> n;
    unordered_map<string, int> dfs_num;

    while (n--) {
        cin >> s1 >> s2;
        graph[s1].push_back(s2);
        dfs_num[s1] = 0;
        dfs_num[s2] = 0;
    }

    while (cin >> s1) {
        control = 0;
        unordered_map<string, int> dfs_num_local(dfs_num);
        dfs(s1, dfs_num_local);
        if (control) {
            cout << s1 << " safe\n";
        } else {
            cout << s1 << " trapped\n";
        }
    }

    return 0;
}
