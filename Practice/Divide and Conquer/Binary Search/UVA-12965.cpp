#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int tc; cin >> tc;

    while (tc--) {
        int p, c; cin >> p >> c;

        vi prod, cons;

        for (int i = 0; i < p; i++) {
            int x; cin >> x;
            prod.push_back(x);
        }
        
        for (int i = 0; i < c; i++) {
            int x; cin >> x;
            cons.push_back(x);
        }

        prod.push_back(0);

        sort(prod.begin(), prod.end());
        sort(cons.begin(), cons.end());

        int val = INF, angry = INF; 
        
        for(int i = 0; i < p + 1; i++) {
            int x = prod[i];
            auto it_cons = lower_bound(cons.begin(), cons.end(), x);

            int temp = (p - i) + distance(cons.begin(), it_cons);

            if(temp < angry) angry = temp, val = x;
        }

        if(prod.empty()) val = 0, angry = 0;

        cout << val << " " << angry << '\n';
    }
    

    return 0;
}