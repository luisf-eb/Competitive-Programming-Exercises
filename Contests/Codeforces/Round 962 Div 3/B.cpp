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
		int n, k;
		cin >> n >> k;
		vector<string> original(n);
		vector<vector<char>> ans(n/k, vector<char>(n/k, '0'));


		for (int i = 0; i < n; i++) {
			cin >> original[i];
		}
		
		for (int i = 0; i < n/k; i++) {
			for (int j = 0; j < n/k; j++) {
				ans[i][j] = original[i*k][j*k];
			}
			
		}
		
		for(auto& x : ans) {
			for(auto& y : x) cout << y;
			cout << '\n';
		}

	}
	return 0;
}