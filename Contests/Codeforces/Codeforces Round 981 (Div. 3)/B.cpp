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

    int tc; 
    cin >> tc;

    while (tc--) {
        int n; 
        cin >> n;
        vector<vi> grid(n, vi(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        int ans = 0;

        for (int start_col = 0; start_col < n; start_col++) {
            int i = 0, j = start_col;
            int max_neg = 0;

            while (i < n && j < n) {
                if (grid[i][j] < 0) {
                    max_neg = max(max_neg, -grid[i][j]);
                }
                i++;
                j++;
            }

            ans += max_neg;
        }

        for (int start_row = 1; start_row < n; start_row++) {
            int i = start_row, j = 0;
            int max_neg = 0;

            while (i < n && j < n) {
                if (grid[i][j] < 0) {
                    max_neg = max(max_neg, -grid[i][j]);
                }
                i++;
                j++;
            }

            ans += max_neg;
        }

        cout << ans << "\n";
    }

    return 0;
}
