#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define LSOne(S) ((S) & -(S))
#define MOD 1000000007

int main() { fastio;
    int cs; cin >> cs;

    while (cs--) {
        int n, k; cin >> n >> k;
        int qtdPares = n/2 - (n-k)/2;
        int qtdImpares = k - qtdPares;


        if(qtdImpares % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    
    

    return 0;
}