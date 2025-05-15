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

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vi vec(n);

        for(auto &x : vec) cin >> x;

        int l = 0, r = n-1;
        while (vec[l] == 0) 
            l++;
        
        
        while (vec[r] == 0) 
            r--;
        
        
        if(l > r) { cout << 0 << "\n"; continue; }

        int flag = 0;
        while (l <= r) {
            if(vec[l] == 0 || vec[r] == 0) { flag = 1; break; }
            l++; r--;
        }
        
        if(flag) cout << 2 << "\n";
        else cout << 1 << "\n";
    }
    

    return 0;
}