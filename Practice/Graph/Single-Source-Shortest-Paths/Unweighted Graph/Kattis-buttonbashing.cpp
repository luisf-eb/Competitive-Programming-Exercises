#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main() { 
    fastio;
    
    int tests;
    cin >> tests;

    while (tests--) {
        int n, t;
        cin >> n >> t;

        vector<int> buttons(n);
        for (int i = 0; i < n; ++i) {
            cin >> buttons[i];
        }

        vector<bool> visited(3601, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;

        int steps = 0, closest = INT_MAX;

        while (!q.empty()) {
            auto [u, s] = q.front(); 
            q.pop();

            if (u == t) {
                steps = s;
                closest = 0;
                break;
            } else if (u > t) {
                if ((u - t) < closest) {
                    closest = u - t;
                    steps = s;
                }
            }

            for (auto &x : buttons) {
                int new_val = u + x;
                if (new_val > 3600) new_val = 3600;
                if (new_val < 0) new_val = 0;

                if (!visited[new_val]) {
                    visited[new_val] = true;
                    q.push({new_val, s + 1});
                }
            }
        }

        cout << steps << " " << closest << '\n';
    }

    return 0;
}
