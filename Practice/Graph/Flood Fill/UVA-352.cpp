#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int n;
int di[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

void floodFill(int i, int j, char c1, char c2, vector<string>& grid) {
    if ( (i < 0) || (i >= n) ) return;
    if ( (j < 0) || (j >= n) ) return;
    if ( grid[i][j] != c1 ) return;

    grid[i][j] = c2;
    for (int d = 0; d < 8; d++) {
        floodFill(i + di[d], j + dj[d], c1, c2, grid);
    }
}

int32_t main() { 
    fastio;
    string input;
    int tests = 0;
    while(cin >> n) {
        vector<string> grid(n);
        grid.clear();
        int total = 0;

        for (int i = 0; i < n; i++) {
            cin >> input;
            grid.push_back(input);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '0') {
                    floodFill(i, j, '1', '0', grid);
                    ++total;
                }
            }
        }
        
        cout << "Image number " << ++tests << " contains " << total <<  " war eagles.\n";

    }
    
   
    return 0;
}
