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

    while (tc--) {
        int n; cin >> n;
        vi vec(n), vet(n);
        
        map<int, int> freq1, freq2;
        
        int cnt = 0;
        for(auto& x : vec) {
            cin >> x;
            if(freq1[x] == 0) cnt++;
            freq1[x]++;
        }

        for(auto& x : vet) {
            cin >> x;
            if(freq2[x] == 0) cnt++;
            freq2[x]++;
        }

        if(cnt > 3) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}