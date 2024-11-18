#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    string s; cin >> s;
    int k; cin >> k;
    vi aux(s.size());

    iota(aux.begin(), aux.end(), 0);
    sort(aux.begin(), aux.end(), [&](auto a, auto b) { return s[a] < s[b];});

    int cont[k] = {0};
    char ans[s.size()];
    for (int i = 0; i < s.size(); i++) {
        int a = aux[i];
        int idx = a%k + k*cont[a%k];
        ++cont[a%k];

        ans[idx] = s[a];
    }
    
    for (int i = 0; i < s.size(); i++) {
        cout << ans[i];
    }
    cout << '\n';
    

    return 0;
}