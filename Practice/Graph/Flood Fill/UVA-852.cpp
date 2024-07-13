#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int control;
int di[] = {1, 0, -1, 0};
int dj[] = {0, -1, 0, 1};

bool isValid(int i, int j) {
    if ( (i < 0 || i >= 9) || (j < 0 || j >= 9)) return false;
    else return true;
}

int floodFill(int i, int j, char c1, char c2, vector<string>& grid) {
    if (!isValid(i,j)) return 0;
    if (grid[i][j] != c1) return 0;

    grid[i][j] = c2;
    int ans = 1;

    for (int d = 0; d < 4; d++) {
        int ni = i + di[d]; 
        int nj = j + dj[d];
        if (isValid(ni, nj)){
            if (grid[ni][nj] == 'X') control |= 1;
            if (grid[ni][nj] == 'O') control |= 2;
            ans += floodFill(ni, nj, c1, c2, grid);
        }
    }

    return ans;
}

int32_t main() { 
    fastio;
    
    int t;
    string entrada;
    cin >> t;
    while (t--) {
        vector<string> grid(9);
        int black = 0, white = 0;
        grid.clear();
        for (int i = 0; i < 9; i++) {
            cin >> entrada;
            grid.push_back(entrada);
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == 'X') black++;
                if (grid[i][j] == 'O') white++;
            }   
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.'){
                    control = 0;
                    int ans = floodFill(i, j, '.', '@', grid);

                    if (control == 1) black += ans;
                    else if(control == 2) white += ans;
                }
            }   
        }

        cout << "Black " << black << " White " << white << '\n';   
    }
    
   
    return 0;
}