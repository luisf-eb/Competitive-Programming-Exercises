#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>

vector<ll> vec;
int n;
ll sum;

ll find(ll x) {
    ll count = 0;
    for (int i = 0; i < n; i++) {
        ll threshold = sum - vec[i] - x;
        int j = upper_bound(vec.begin() + i + 1, vec.end(), threshold) - vec.begin();
        count += (n - j);
    }
    return count;
}

int main() { 
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc; 
    cin >> tc;
    while (tc--) {
        ll x, y;
        cin >> n >> x >> y;

        vec.resize(n);
        sum = 0;

        for (auto& val : vec) {
            cin >> val;
            sum += val;
        }

        sort(vec.begin(), vec.end());      

        cout << (find(y + 1) - find(x)) << "\n";
    }
    return 0;
}
