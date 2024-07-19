#include <bits/stdc++.h>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);

        reverse(perm.begin(), perm.end());
        reverse(perm.end() - m, perm.end());
        
        for (int i = 0; i < n; i++) {
            if(i == n-1) cout << perm[i] << '\n';
            else cout << perm[i] << " ";
        }
    }
    
    return 0;
}
