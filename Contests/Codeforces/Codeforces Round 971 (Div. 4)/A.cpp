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
        int a, b; cin >> a >> b;
        cout << (2*a-a) + (b-2*a) << '\n';
    }
    

    return 0;
}