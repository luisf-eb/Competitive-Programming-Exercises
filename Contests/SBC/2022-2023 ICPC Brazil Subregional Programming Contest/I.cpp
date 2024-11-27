#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    for (int i = 0; i < 8; i++) {
        int x; cin >> x;
        if(x == 9) {
            cout << "F\n";
            exit(0);
        }
    }


    cout << "S\n";

    return 0;
}