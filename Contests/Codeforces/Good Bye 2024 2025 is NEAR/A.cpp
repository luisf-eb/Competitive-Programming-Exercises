#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

vi vec;
int x, y;

bool verify() {
    if(vec.size() == 3) {
        return vec[0] + vec[1] > vec[2] &&
               vec[1] + vec[2] > vec[0] &&
               vec[2] + vec[0] > vec[1];
    }

    vec.push_back(x);
    bool a = verify();
    vec.pop_back();

    vec.push_back(y);
    bool b = verify();
    vec.pop_back();

    return a && b;
}

int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;

        vi vet(n);

        for(auto& x : vet) cin >> x;

        bool ans = false;
        for (int i = 0; i < n-1; i++) {
            vec.clear();
            x = vet[i];
            y = vet[i+1];
            ans = verify();
            if(ans) break; 
        }
        
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}