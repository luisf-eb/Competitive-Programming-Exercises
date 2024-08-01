#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

	int tc;
	cin >> tc;

	while(tc--){
        int n, q; cin >> n >> q;
        string a, b; cin >> a >> b;

        vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
        vector<vector<int>> pre2(n + 1, vector<int>(26, 0));

        for (int i = 1; i <= n; i++) {
            int letter1 = a[i-1] - 'a';
            int letter2 = b[i-1] - 'a';
    
            pre1[i][letter1]++;
            pre2[i][letter2]++;
            
            for (int j = 0; j < 26; j++) {
                pre1[i][j] += pre1[i - 1][j];
                pre2[i][j] += pre2[i - 1][j];
            }
        }

        while (q--) {
            int l, r; cin >> l >> r;
            int ans = 0;

            for (int i = 0; i < 26; i++) {
                int c1 = pre1[r][i] - pre1[l - 1][i];
                int c2 = pre2[r][i] - pre2[l - 1][i];

                int diff = abs(c2 - c1);

                ans += diff;
            }

            cout << ans/2 << '\n';
        }
	}
	return 0;
}