#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { 
    fastio;

    int m;
    vector<ll> vec;

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 20; j++) {
            ll num = (ll) (pow(2, i) * pow(3, j));
            if (num > (1LL << 31))
                break;
            vec.push_back(num);
        }
    }
    
    sort(vec.begin(), vec.end());

    while (cin >> m && m) {
        cout << *lower_bound(vec.begin(), vec.end(), m) << '\n';
    }

    return 0;
}
