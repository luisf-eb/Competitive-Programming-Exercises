#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { //fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc; cin >> tc;

    while (tc--) {
        int n, k; cin >> n >> k;
        vi vec(n);
        
        for(auto& x : vec) cin >> x;

        sort(vec.begin(), vec.end());

        int i = n-1, sum = 0;
        while (i >= 0 && sum < k) {
            if(sum + vec[i] > k) break;
            sum += vec[i];
            i--;
        }

        cout << k - sum << "\n";
    }
    

    return 0;
}