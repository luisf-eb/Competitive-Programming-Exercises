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
    int freq[101];
    while (tc--) {
        int n, f, k; cin >> n >> f >> k;
        memset(freq, 0, sizeof freq);

        vi vec(n);
        for(auto& x : vec) { cin >> x; freq[x]++; }

        int pref = vec[f-1];

        sort(vec.begin(), vec.end(), greater<int>());
    
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if(vec[i] == pref) cnt++;
        }
        
        if(cnt >= freq[pref]) cout << "YES\n";
        else if(cnt < freq[pref] && cnt > 0) cout << "MAYBE\n";
        else if(cnt == 0) cout << "NO\n";
    }
        

    return 0;
}