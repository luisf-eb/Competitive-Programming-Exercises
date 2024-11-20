#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int n, tc, cs = 1;
vi w, h;

int lis() {
    int memo[n];
    for (int i = 0; i < n; i++) memo[i] = w[i];    

    int ans = memo[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (h[j] < h[i]) 
                memo[i] = max(memo[i], memo[j] + w[i]);
        }
        ans = max(ans, memo[i]);
    }
    
    return ans;
}

int main() { 
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    cin >> tc;
    while (tc--) {
        cin >> n;
        h.resize(n); 
        w.resize(n);

        for (auto& x : h) cin >> x;
        for (auto& x : w) cin >> x;

        int inc = lis();
        reverse(h.begin(), h.end());
        reverse(w.begin(), w.end());
        int des = lis();

        cout << "Case " << cs++ << ". ";
        if (inc >= des) 
            cout << "Increasing (" << inc << "). Decreasing (" << des << ").\n";
        else 
            cout << "Decreasing (" << des << "). Increasing (" << inc << ").\n";
    }

    return 0;
}
