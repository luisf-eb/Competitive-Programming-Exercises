#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n;
        cin >> n;
        
        int x; cin >> x;

        vector<int> visited(n, 0);
        visited[x-1] = 1;

        int flag = 1;
        for (int i = 1; i < n; i++) {
            cin >> x; x--;
            visited[x] = 1;
            
            if(x == 0 && visited[x+1] == 0) flag = 0;
            if(x == n-1 && visited[x-1] == 0) flag = 0;
            else if (visited[x+1] == 0 && visited[x-1] == 0) flag = 0;   
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
