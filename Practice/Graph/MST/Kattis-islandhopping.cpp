#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<int> p, r;

int findSet(int i) {
    if (p[i] == i) return i;
    return p[i] = findSet(p[i]);
}

void unionSet(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if(x == y) return;

    if (r[x] > r[y]) swap(x, y);
    p[x] = y;

    if(r[x] == r[y]) r[y]++;
}

int main() {
    fastio;
    int t, m;
    cin >> t;
    
    while (t--) {
        cin >> m;
        vector<pair<double, double>> coordinates(m);
        r.assign(m, 0);
        p.resize(m);
        iota(p.begin(), p.end(), 0);

        for (int i = 0; i < m; i++) {
            cin >> coordinates[i].first >> coordinates[i].second;
        }

        vector<tuple<double, int, int>> EL;
        EL.reserve(m * m);

        for (int i = 0; i < m-1; i++) {
            for (int j = i+1; j < m; j++){
                double dx = coordinates[i].first - coordinates[j].first;
                double dy = coordinates[i].second - coordinates[j].second;
                double distance = sqrt((dx*dx)+(dy*dy));
                EL.push_back({distance, i, j});
            }
        }
        
        sort(EL.begin(), EL.end());

        double total = 0;
        int runs = 0;
        for(auto& [d, u, v] : EL) {
            if(findSet(u) == findSet(v)) continue;
            total += d;
            unionSet(u, v);
            ++runs;
            if(runs == m-1) break;
        }

        cout << fixed << setprecision(3) << total << '\n';
    }

    return 0;
}
