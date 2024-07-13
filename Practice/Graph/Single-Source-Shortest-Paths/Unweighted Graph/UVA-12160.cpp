#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main() { //fastio;
    
    int l, u, r, b, cases = 1;

    while (cin >> l >> u >> r) {
        if(l == 0 && u == 0 && r == 0) break;
        
        vector<int> buttons;
        vector<int> visited(10000, 0);
        while (r--) {
            cin >> b;
            buttons.push_back(b);
        }

        int total = 0;
        queue<pair<int, int>> q;
        q.push({l, 0});
        visited[l] = 1;
        while(!q.empty()) {
            auto [val, steps] = q.front(); q.pop();

            if(val == u) {
                total = steps;
                break;
            }

            for(auto& button : buttons) {
                int newVal = (val + button) % 10000;
                if(!visited[newVal]) {
                    visited[newVal] = 1;
                    q.push({newVal, steps+1});
                }
            }
        }

        if(total)
            cout << "Case " << cases++ << ": " << total << '\n';
        else
            cout << "Case " << cases++ << ": Permanently Locked" << '\n';
    }
    

return 0;
}