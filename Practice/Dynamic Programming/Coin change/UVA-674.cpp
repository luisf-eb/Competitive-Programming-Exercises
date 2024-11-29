#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() {
    fastio;

    int n;
    vi coins = {50, 25, 10, 5, 1};

    while (cin >> n) {
        vi memo(n + 1, 0);
        memo[0] = 1; 
        
        for (auto& coin : coins) {
            for (int i = coin; i <= n; i++) {
                memo[i] += memo[i - coin];
            }
        }

        cout << memo[n] << '\n';
    }

    return 0;
}
