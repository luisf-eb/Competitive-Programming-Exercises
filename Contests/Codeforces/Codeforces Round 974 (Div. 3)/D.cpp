#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int cs; cin >> cs;

    while (cs--) {
        int n, d, k; cin >> n >> d >> k;
        vi ps(n+1, 0), es(n+1, 0);

        while (k--) {
            int l, r; cin >> l >> r;
            ++ps[l];
            ++es[r];
        }

        for (int i = 1; i <= n; i++) ps[i] += ps[i-1];
        for (int i = 1; i <= n; i++) es[i] += es[i-1];
        
        int minimo = INF, ansM = 1;
        int maximo = 0, ansB = 1;
        
        for (int i = d; i <= n; i++) {
            int val = ps[i] - es[i-d]; 

            if(val < minimo) {
                minimo = val;
                ansM = i-d+1;
            }

            if(val > maximo) {
                maximo = val;
                ansB = i-d+1;
            }
        }
        

        cout << ansB << " " << ansM << "\n";
    }
       

    return 0;
}