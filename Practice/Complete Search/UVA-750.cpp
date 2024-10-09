#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int a, b, rows[8], counter;

bool isValid(int r, int c) {
    for (int i = 0; i < c; i++) {
        if(rows[i] == r || abs(r-rows[i]) == abs(c - i)) return false;
    }
    
    return true;
}

void backtracking(int c) {
    if(c == 8 && rows[b] == a) {
        cout << setw(2) << ++counter << "      ";
        for (int i = 0; i < 7; i++) {
            cout << rows[i] + 1 << " ";
        }
        cout << rows[7] + 1 << "\n";
    }

    for (int r = 0; r < 8; r++) {
        if(r == a && c != b) continue;
        if(isValid(r, c)) rows[c] = r, backtracking(c+1);
    }
}

int main() { fastio;

    int tc; cin >> tc;

    while (tc --) {
        cin >> a >> b;
        a--; b--;
        memset(rows, 0, sizeof(rows));

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        counter = 0;
        backtracking(0);

        if(tc) cout << "\n";
    }
    

    return 0;
}