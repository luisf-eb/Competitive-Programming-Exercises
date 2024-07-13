#include <bits/stdc++.h>

using namespace std;

vector<int> p, t, ranking;

int findSet(int x) {
    if (p[x] == x) return x;

    return p[x] = findSet(p[x]);
}

void UnionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x==y) return;
    if (ranking[x] > ranking[y]) swap(x, y);
    p[x] = y;

    if (ranking[x] == ranking[y]) ++ranking[y];

    t[y] += t[x];
}

int main() {
    int n, m;

    while (cin>>n>>m and (n != 0 or m != 0)){
        int k;
        int temp;

        t.assign(n, 1);
        ranking.assign(n, 0);
        p.assign(n, 0);

        for (int i = 0; i < n; i++) {
            p[i] = i;
        }

        for (int j = 0; j < m; j++) {
            cin >> k;
            vector<int> aux(k);
            for (int i = 0; i < k; i++){
                cin >> temp;
                aux[i] = temp;
            }

            for (int i = 0; i < k-1; i++) {
                UnionSet(aux[0], aux[i+1]);
            }
        }

        int setInfectados = findSet(0);

        cout << t[setInfectados] << '\n';
    }

return 0;
}