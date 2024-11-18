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

        vi vec(n), aux(n);

        for(auto &elem : vec) cin >> elem;

        aux[0] = vec[0], aux[n-1] = vec[n-1];
        int i = 1, j = n-2;
        while (i <= j) {
            int change = (vec[i] == aux[j+1]) + (vec[j] == aux[i-1]);
            int notChange = (vec[i] == aux[i-1]) + (vec[j] == aux[j+1]);

            //cout << i << " : " << j << " Change = " << change << " notChange = " << notChange << "\n";

            if(change < notChange) aux[i] = vec[j], aux[j] = vec[i];
            else aux[i] = vec[i], aux[j] = vec[j];

            ++i; --j;
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += aux[i] == aux[i-1];
        }
        
        
        cout << ans << "\n";
    }
       

    return 0;
}