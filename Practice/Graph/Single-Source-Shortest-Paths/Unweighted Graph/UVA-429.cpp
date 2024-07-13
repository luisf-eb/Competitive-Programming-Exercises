#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

unordered_map<string, vector<string>> graph;

void process(vector<string>& words) {
    int sz = words.size();

    for (int i = 0; i < sz-1; i++) {
        for (int j = i+1; j < sz; j++) {
            string s1 = words[i];
            string s2 = words[j];
            int differs = 0;

            if(s1.size() != s2.size()) continue;

            for (int k = 0; k < s1.size(); k++) {
                if(s1[k] != s2[k]) differs++;
            }
            
            if(differs == 1) {
                graph[s1].push_back(s2);
                graph[s2].push_back(s1);
            }
        }
        
    }
    
} 

int main() { fastio;
    int t;
    string s;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--) {
        vector<string> words;
        graph.clear();
        while (getline(cin, s) && s != "*") words.push_back(s);
        
        process(words);

        while (getline(cin, s) && !s.empty()) {
            stringstream ss(s);
            string starting, ending;
            ss >> starting >> ending;

            unordered_map<string, int> visited;
            int steps;
            queue<pair<string, int>> q; q.push({starting, 0});
            visited[starting] = 1;

            while (!q.empty()) {
                auto [u, d] = q.front(); q.pop();

                if(u == ending) {
                    steps = d;
                    break;
                }

                for(auto& v : graph[u]) {
                    if(!visited[v]) {
                        visited[v] = 1;
                        q.push({v, d+1});
                    }
                }
            }

            cout << starting << " " << ending << " " << steps << '\n';
        }
        
        if(t) cout << '\n';
    }
    

return 0;
}