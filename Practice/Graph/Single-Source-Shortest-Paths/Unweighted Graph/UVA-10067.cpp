#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

	int tc, buttons[2] = {1, -1};
	cin >> tc;

	while(tc--){
        vector<int> visited(10000, 0);
		int initial = 0, final = 0, f;
        for (int i = 0; i < 4; i++) {
            int x; cin >> x;
            initial = initial * 10 + x;
        }
        for (int i = 0; i < 4; i++) {
            int x; cin >> x;
            final = final * 10 + x;
        }
        
        cin >> f;
        while (f--) {
            int val = 0;
            for (int i = 0; i < 4; i++){
                int x; cin >> x;
                val = val * 10 + x;
            }
            visited[val] = -1;
        }
        
        queue<ii> q;
        q.push({initial, 0}); 
        visited[initial] = 1;

        bool found = false;
        while (!q.empty()){
            auto [u, steps] = q.front(); q.pop();

            if(u == final) {
                cout << steps << '\n';
                found = true;
                break;
            }
            
            string curr = to_string(u);
            while (curr.size() < 4) curr = "0" + curr;

            for (int i = 0; i < 4; i++) {
                string temp = curr;
                int c = temp[i] - '0';

                for(auto& b : buttons) {
                    int new_c = (c + b + 10) % 10;
                    temp[i] = new_c + '0';

                    int newVal = stoi(temp);
                    if(visited[newVal] == 0) {
                        visited[newVal] = 1;
                        q.push({newVal, steps + 1});
                    }
                }
            }
        }
        
        if(!found) cout << -1 << '\n';
	}
	return 0;
}
