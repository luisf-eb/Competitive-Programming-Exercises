#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n, q; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cin >> q;
        while (q--) {
            string s; cin >> s;

            if(s.size() != n) {
                cout << "NO\n";
                continue;
            }

            unordered_map<char, int> m1;
            unordered_map<int, char> m2;
            int flag = 1;
            for (int i = 0; i < n; i++) {
                char c = s[i];
                int x = a[i];

                if(m1.find(c) == m1.end()) m1[c] = x;
                if(m2.find(x) == m2.end()) m2[x] = c;
                if(m1[c] != x || m2[x] != c) {
                    flag = 0;
                    break;
                }
            }   
            
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
        
        
    }

    return 0;
}
