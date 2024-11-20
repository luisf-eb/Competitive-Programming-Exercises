#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int AM[100][100], FW[100][100], p[100][100], n, ans = 0;

void check(int i, int j) {

}

int main() { fastio;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            FW[i][j] = INF;
            p[i][j] = 0;
        }
        FW[i][i] = INF;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            AM[i][j] = x;
            FW[i][j] = x;
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(FW[i][k] + FW[k][j] <= FW[i][j]) {
                    FW[i][j] = FW[i][k] + FW[k][j];
                    p[i][j]++; 
                }    
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++){
            if(FW[i][j] < AM[i][j]) { cout << -1 << '\n'; exit(0); }
            if(p[i][j] - 1 > 1) ans++;
        }
    }
    
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++) {
    //         cout << p[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    cout << ans << "\n";

    return 0;
}