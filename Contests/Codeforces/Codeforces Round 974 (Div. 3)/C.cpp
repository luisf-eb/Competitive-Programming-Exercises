#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int cs; cin >> cs;

    while (cs--) {
        long long n; cin >> n;
        long long sum = 0;

        vector<long long> vec(n);


        for(auto &x : vec) {
            cin >> x;
            sum += x;
        }

        sort(vec.begin(), vec.end());

        if(n <= 2) {
            cout << "-1\n";
            continue;
        }

        ll ans = max(0LL, vec[n/2]*2*n-sum+1);
        cout << ans << '\n';
    }
    

    return 0;
}