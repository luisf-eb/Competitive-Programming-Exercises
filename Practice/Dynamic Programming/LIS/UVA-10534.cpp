#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int n;
    while (cin >> n) {
        vi A(n), L(n, 0), lis(n, 0);
        int k = 0;

        for (int i = 0; i < n; i++) cin >> A[i];
        
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
            L[pos] = A[i];
            lis[i] = pos + 1;
            if (pos == k) ++k;
        }
        
        reverse(A.begin(), A.end());

        vi L2(n, 0), lis2(n, 0);
        int k2 = 0;
        
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(L2.begin(), L2.begin() + k2, A[i]) - L2.begin();
            L2[pos] = A[i];
            lis2[i] = pos + 1;
            if (pos == k2) ++k2;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, min(lis[i], lis2[n - i - 1]) * 2 - 1);
        }

        cout << ans << '\n';
    }

    return 0;
}
