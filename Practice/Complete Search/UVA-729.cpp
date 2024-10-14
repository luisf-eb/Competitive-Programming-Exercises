#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int tc; cin >> tc;
    
    while(tc--) {
        int N, H; cin >> N >> H;
        int vec[N];
        memset(vec, 0, sizeof(vec));

        for (int i = N-1; i >= N-H ; --i) {
            vec[i] = 1;
        }

        do {
            for (int i = 0; i < N; ++i) {
                cout << vec[i];
            }
            cout << endl;
        } while (next_permutation(vec, vec+N));
        
        if(tc) cout << '\n';
    }

    return 0;
}