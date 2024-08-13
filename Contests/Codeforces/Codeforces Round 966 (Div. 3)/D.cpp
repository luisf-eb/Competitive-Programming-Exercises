#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n; cin >> n;
        vector<long long> prefix(n+1, 0);
        vector<int> a(n); 
        string s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + a[i-1];
        }

        cin >> s;

        int i = 0;
        int j = n-1;
        long long ans = 0;

        while (i < j) { 
            if(s[i] == 'R') {
                i++;
                continue;
            }
            if(s[j] == 'L') {
                j--;
                continue;
            }

            ans += prefix[j+1] - prefix[i];
            ++i;
            --j;
        }
        
        cout << ans << '\n';
    }

    return 0;
}
