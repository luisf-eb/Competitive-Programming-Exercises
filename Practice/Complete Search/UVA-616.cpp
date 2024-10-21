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

    while (cin >> n  && n != -1) {

        int ans = 0, raizN = ceil(sqrt(n));

        for (int i = 1; i <= raizN; i++){
            int flag = 0, aux = n;

            for (int j = 1; j <= i; j++){
                if(aux % i != 1) { flag = 1; break; };
                aux -= (aux/i) + 1;
            }

            if(flag) continue;
            if(aux % i == 0) ans = i;
        }

        cout << n << " coconuts, ";
        if(ans) cout << ans << " people and 1 monkey\n";
        else cout << "no solution\n";
    }

    return 0;
}