#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int ans = 0;
        vector<int> b = {b1, b2};

        for (int i = 0; i < 2; i++) {
            if ( (a1 > b[i] && a2 >= b[(i+1)%2]) || (a1 >= b[i] && a2 > b[(i+1)%2])) ans++;
        }

        for (int i = 0; i < 2; i++) {
            if ( (a2 > b[i] && a1 >= b[(i+1)%2])  || (a2 >= b[i] && a1 > b[(i+1)%2])) ans++;
        }
        
        cout << ans << '\n';
    }
    return 0;
}
