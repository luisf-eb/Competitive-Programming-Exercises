#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int n, m, x; 
    int A[101][101];
    while (cin >> n >> m) {
        if(!m && !n) break;

        memset(A, 0, sizeof(A));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                A[i][j] = (x == 1) ? 0 : 1; 
                if(j > 0) A[i][j] += A[i][j-1];
            }
        }
        

        int ans = 0;
        for (int l = 0; l < m; l++) {
            for (int r = l; r < m; r++) {
                int aux = 0, qtd = r - l + 1;

                for (int row = 0; row < n; row++) {
                    int y;
                    if(l) y = A[row][r] - A[row][l-1];
                    else y = A[row][r];

                    aux += y;
                    if(y < qtd) aux = 0;
                    ans = max(ans, aux);
                }
                
            }
        }
        
        cout << ans << '\n';
    }
    

    return 0;
}