#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n, x, ans, freq[14]; cin >> n;
    int joao = 0;
    int maria = 0;
    memset(freq, 0, sizeof freq);

    for (int i = 0; i < 2; i++) {
        cin >> x;
        ++freq[x];
        if(x == 11 || x == 12 || x == 13) x = 10;
        joao += x;
    }
    
    for (int i = 0; i < 2; i++) {
        cin >> x;
        ++freq[x];
        if(x == 11 || x == 12 || x == 13) x = 10;
        maria += x;
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        ++freq[x];
        if(x == 11 || x == 12 || x == 13) x = 10;
        maria += x;
        joao += x;
    }
    
    ans = INF;
    for (int i = 1; i <= 13; i++) {
        if(freq[i] < 4) {
            x = i;
            if(x > 10) x = 10;
            if(joao + x > 23 && maria + x <= 23) ans = min(ans, i);
            else if(maria + x == 23) ans = min(ans, i);
        }
    }

    if(ans == INF) ans = -1;

    cout << ans << "\n";

    return 0;
}