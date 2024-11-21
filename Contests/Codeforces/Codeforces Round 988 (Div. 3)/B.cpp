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
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif  

    int tc; cin >> tc;
    while (tc--) {
        int k; cin >> k;
        vi vec(k);
        for(auto& x : vec) cin >> x;
        sort(vec.begin(), vec.end());

        int elem = k-2;
        int i = 0, j = k-1;
        while (i < j) {
            int x = vec[i]*vec[j];
            if(x == elem) {
                cout << vec[i] << " " << vec[j] << '\n';
                break;
            }
            if(x < elem) i++;
            if(x > elem) j--;
        }
        
    }
    

    return 0;
}