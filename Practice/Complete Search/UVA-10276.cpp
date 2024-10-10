#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

bitset<INF> hasSqrt;
vector<vi> pegs;
int n;

void generateSqrt() {
    for(int i = 1; i < 10000; i++) if(i*i > 0) hasSqrt[i*i] = 1;
}

int solve(int i) {
    for (int j = 0; j < n; j++) {
        if(pegs[j].size() == 0) {
            pegs[j].push_back(i);
            return solve(i+1);
        }
        else if(hasSqrt[pegs[j].back() + i]) {
            pegs[j].push_back(i);
            return solve(i+1);
        }
    }
    
    return i - 1;
}
 
int main() { fastio;

    int tc; cin >> tc;
    generateSqrt();

    while(tc--) {
        cin >> n;

        pegs.assign(n, vi());
        int ans = solve(1);

        cout << ans << "\n";
    }

    return 0;
}