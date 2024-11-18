#include <bits/stdc++.h>

using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;
    int n;
    cin >> n;
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long ans = 0;
    int odds = 0, evens = 1;
    int xorFlag = 0;

    for (int i = 0; i < n; ++i) {
        xorFlag ^= b[i];

        if (!xorFlag) {
            ans += odds;
            evens++;
        } else {
            ans += evens;
            odds++;
        }
    }

    cout << ans << endl;
    return 0;
}
