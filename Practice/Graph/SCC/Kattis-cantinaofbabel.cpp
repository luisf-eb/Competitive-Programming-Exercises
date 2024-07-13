#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
unordered_map<string, int> visited;
unordered_map<string, vector<string>> languages, graph, graphT, pending;
vector<string> S, persons;


void dfs(string u) {
    visited[u] = 1;
    for (auto& v : graph[u]) {
        if(!visited[v]) dfs(v);
    }
    S.push_back(u);
}

void dfsT(string u, vector<string>& group) {
    visited[u] = 1;
    for (auto& v : graphT[u]) {
        if(!visited[v]) dfsT(v, group);
    }
    group.push_back(u);
}

int32_t main() { fastio;
    int n;
    cin >> n;
    cin.ignore();

    languages.clear(); graph.clear(); graphT.clear(); pending.clear(); persons.clear();
    unordered_map<string, int> visitedTemp;

    for (int i = 0; i < n; i++) {
        string s, name, l;
        getline(cin, s);
        stringstream ss(s);

        ss >> name;
        ss >> l;
        persons.push_back(name);
        languages[l].push_back(name);
        pending[l].push_back(name);
        visitedTemp[name] = 0;
        while (ss >> l) {
            pending[l].push_back(name);
        }
    }

    for (auto& lang : pending) {
        for (auto& person : lang.second) {
            for (auto& speaker : languages[lang.first]) {
                graph[person].push_back(speaker);
                graphT[speaker].push_back(person);
            }
        }
    }

    visited = visitedTemp;
    for(auto& u : persons) {
        if(!visited[u]) dfs(u);
    }
    
    visited = visitedTemp;
    int biggestGroup = 0;
    for (int i = S.size() - 1; i >= 0; --i) {
        if(!visited[S[i]]) {
            vector<string> group;
            group.clear();
            dfsT(S[i], group);

            biggestGroup = max((int)group.size(), biggestGroup);
        }
    }

    cout << n - biggestGroup << '\n';
    
return 0;
}