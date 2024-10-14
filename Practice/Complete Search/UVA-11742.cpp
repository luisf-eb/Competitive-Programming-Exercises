#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n, m;

    while(cin >> n >> m, n || m) {
        vector<tuple<int, int, int>> constraints(m);
        int vec[n];

        for (int i = 0; i < n; i++) vec[i] = i;
        for(auto& [a, b, c] : constraints) cin >> a >> b >> c;


        int ans = 0;
        do {
            int flag = 1;

            for(auto& [a, b, c] : constraints) {
                int seatA = vec[a];
                int seatB = vec[b];

                if(c < 0 && abs(seatA - seatB) < abs(c)) { flag = 0; break; }
                else if(c > 0 && abs(seatA - seatB) > c) { flag = 0; break; }
            }

            if(flag) ++ans;

        } while (next_permutation(vec, vec+n));
        
        cout << ans << '\n';
    } 

    return 0;
}