#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ii pair<int, int>
#define vi vector<int>

int n, X, Y;

int solveX(int x) {
    if(x == X || x&1) return x == X ? 0 : INF;
    int ans = INF;
    ans = min(ans, solveX((x+(1<<n))/2) + 1);
    ans = min(ans, solveX(x/2) + 1);
    return ans;
}

int solveY(int y) {
    if(y == Y || y&1) return y == Y ? 0 : INF;
    int ans = INF;
    ans = min(ans, solveY((y+(1<<n))/2) + 1);
    ans = min(ans, solveY(y/2) + 1);
    return ans;
}

int main() {
    fastio;
     
    cin >> n >> X >> Y;

    cout << solveX(1<<n-1) << '\n';

    return 0;
}
