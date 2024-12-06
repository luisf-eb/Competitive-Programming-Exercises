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

    int tc;
    cin >> tc;
    string s;

    while (tc--) {
        cin >> s;
        
        int sum = 0, qtd3 = 0, qtd2 = 0, flag = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
            if(s[i] == '3') qtd3++;
            if(s[i] == '2') qtd2++;
        }
        
        if(sum%9 == 0) flag = 1;
        else {
            for (int i = 0; i <= qtd2; i++) {
                if(flag) break;
                for (int j = 0; j <= qtd3; j++) {
                    int aux = sum + (i*2) + (j*6);
                    if(aux % 9 == 0) { flag = 1; break; }
                }
            }
        }
        
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}