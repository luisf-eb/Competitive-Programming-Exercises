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

        while (cin >> n) {
            vi vec(n);
            
            for(auto& x : vec) cin >> x;

            int m; cin >> m;
            sort(vec.begin(), vec.end());

            int i = 0, j = n-1;
            ii ans;
            while (i < j) {
                int sum = vec[i] + vec[j];
                if(sum == m) { ans = {vec[i], vec[j]}; i++, j--; }
                if(sum < m) i++;
                if(sum > m) j--;
            }
            
            cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << ".\n\n";

        }
        

        return 0;
    }