#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int rows, col, enter, total_cycle;
map<char, pair<int, int>> d = { {'N', {-1, 0} }, {'E', {0, 1} }, {'S', {1, 0} }, {'W', {0, -1} } };
vector<vector<int>> dfs_num;

int dfs(int i, int j, vector<string> grid) {
    if ( (i < 0) || (i >= rows) ) return 0;
    if ( (j < 0) || (j >= col) ) return 0;
    if ( dfs_num[i][j] == 1 ) {
        dfs_num[i][j] = 2;
        return 0;
    }

    dfs_num[i][j] = 1; //explored

    int ni = i + d[grid[i][j]].first;
    int nj = j + d[grid[i][j]].second;
    int ans = 1 + dfs(ni, nj, grid);
    
    if (dfs_num[i][j] == 2) {
        total_cycle = ans;
        return 0;
    } else return ans;
}

int32_t main() {
    fastio;

    string s1;

    while (cin >> rows >> col >> enter and rows != 0 and col != 0 and enter != 0) {
        vector<string> grid;
        grid.clear();
        dfs_num.assign(rows, vector<int>(col, 0));
        for (int i = 0; i < rows; i++) {
            cin >> s1;
            grid.push_back(s1);
        }

        enter--;
        total_cycle = 0;
        int ans = dfs(0, enter, grid);
        if (!total_cycle) cout << ans << " step(s) to exit\n";
        else cout << ans << " step(s) before a loop of " << total_cycle << " step(s)\n";
    }
    

    return 0;
}
