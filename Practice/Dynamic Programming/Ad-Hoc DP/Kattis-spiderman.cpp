#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

vi vec;
int memo[41][1001], n, p[41][1001];

int dp(int i, int h) {
    if(i == n) return (h == 0) ? 0 : INF;

    int &ans = memo[i][h];

    if(ans != -1) return ans;

    int up = max(dp(i+1, h+vec[i]), h+vec[i]);
    int down = (h-vec[i] >= 0) ? dp(i+1, h-vec[i]) : INF;

    if(down < up) p[i][h] = 1;

    return ans = min(up, down); 
}

int main() { fastio;
    int tc; cin >> tc;

    while (tc--) {
        cin >> n;
        vec.resize(n);
        memset(memo, -1, sizeof memo);
        memset(p, 0, sizeof p);

        for(auto &x : vec) cin >> x;

        int res = dp(0, 0);

        if(res >= INF) cout << "IMPOSSIBLE\n";
        else {
            string ans = "";
            int idx = 0, h = 0;
            while (idx != n) {
                if(p[idx][h]) {
                    ans += 'D';
                    h -= vec[idx];
                }
                else {
                    ans += 'U';
                    h += vec[idx];
                }

                ++idx;
            }
            
            cout << ans << "\n";
        }
    }
    
    

    return 0;
}