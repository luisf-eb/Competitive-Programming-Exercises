#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int r[400010];
int l[400010];
int freq[400010], pf[400010];


int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        memset(freq, 0, sizeof freq);
        memset(pf, 0, sizeof pf);

        for (int i = 0; i < n; i++){
            cin>>l[i]>>r[i];
            if(l[i] == r[i]) pf[l[i]] = 1, freq[l[i]]++;
        }
        
        for (int i = 2; i <= n*2; i++) pf[i] += pf[i-1];

        for (int i = 0; i < n; i++) {
            if(l[i] == r[i]) cout << (freq[l[i]] <= 1 ? '1' : '0');
            else cout << (pf[r[i]] - pf[l[i] - 1] < r[i]-l[i]+1 ? '1' : '0');
        }
        
        cout << "\n";
    }
    

    return 0;
}