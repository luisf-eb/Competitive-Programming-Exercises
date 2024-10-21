#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

vi vec;

int test(int k) {
    if (vec[0] > k) return 0;
    if (vec[0] == k) k--;

    for (int i = 0; i < vec.size() - 1; i++) {
        int diff = vec[i+1] - vec[i];
        if(diff > k) return 0;
        if(diff == k) k--;
    }

    return 1;
}

int main() { 
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc, cs = 1; cin >> tc;

    while (tc--) {
        int n; cin >> n;
        vec.assign(n, 0);

        for(auto& x : vec) cin >> x;

        int ini = 1, end = vec[n-1];
        int ans = 0;
        
        while (ini <= end) {
            int k = (ini + end) / 2;

            if(test(k)) { ans = k; end = k - 1; }
            else  ini = k + 1;
        }
        
        cout << "Case " << cs++ << ": ";
        cout << ans << "\n";
    }

    return 0;
}
