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
    
    int tc;
    cin >> tc;
    int freq[200010];

    while (tc--) {
        int n; cin >> n;

        vi vec(n), ans(n);
        memset(freq, 0, sizeof freq);

        for(auto &x : vec) cin >> x;

        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            int x = vec[i];
            if(!freq[x]) {
                ans[i] = x;
                freq[x] = 1;
            } else q.push(i);
        }

        int aux = 1;
        while (!q.empty()) {
            int idx = q.front(); q.pop();

            while (freq[aux] != 0) aux++;

            ans[idx] = aux;
            freq[aux]++;
        }
        
        
        for(auto& x : ans) cout << x << " ";
        cout << "\n";
    }   
    

    return 0;
}