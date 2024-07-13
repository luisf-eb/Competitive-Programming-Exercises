#include <bits/stdc++.h>

using namespace std;

vector<int> p, t, ranking;

int findSet(int x) {
    if (p[x] == x) return x;

    return p[x] = findSet(p[x]);
}

void UnionSet(int i, int j) {
    if (findSet(i) == findSet(j)) return;
    int x = findSet(i), y = findSet(j);
    
    if (ranking[x] > ranking[y]) swap(x, y); 
    p[x] = y;

    if (ranking[x] == ranking[y]) ++ranking[y];
    t[y] += t[x];
}

int main() {
/////////////////////////////////////////////////////////////////////////////////////////////
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

////////////////////////////////////////////////////////////////////////////////////////////
    int c, r;
    string c1, c2;
    while(cin >> c >> r && c) {
        unordered_map<string, int> criaturas;

        p.assign(c, 0);
        ranking.assign(c, 0);
        t.assign(c, 1);
        
        for(int i = 0; i < c; i++){        
            cin >> c1;
            criaturas.emplace(c1, i);
            p[i] = i;
        }

        for (int i = 0; i < r; i++) {
            cin >> c1 >> c2;
            UnionSet(criaturas[c1], criaturas[c2]);
        }

        int maior = 0;

        for (int i = 0; i < c; i++) if (t[i] > maior) maior = t[i];

        cout << maior << "\n";
    }
return 0;
}