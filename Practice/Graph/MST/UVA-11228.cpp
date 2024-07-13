#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef vector<int> vi;

class UnionFind {
    private:
        vi p, rank, setSize;
        int numSets;
    public:
        UnionFind(int N) {
            p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
            rank.assign(N, 0);
            setSize.assign(N, 1);
            numSets = N;
        }

        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        int numDisjointSets() { return numSets; }
        int sizeOfSet(int i) { return setSize[findSet(i)]; }

        void unionSet(int i, int j) {
            if (isSameSet(i, j)) return;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
            setSize[y] += setSize[x];
            --numSets;
        }
};

int main() {
    fastio;
    int t, m, radius, cases = 1;
    cin >> t;
    
    while (t--) {
        cin >> m >> radius;
        vector<pair<double, double>> coordinates(m);

        for (int i = 0; i < m; i++) {
            cin >> coordinates[i].first >> coordinates[i].second;
        }

        vector<tuple<double, int, int>> EL, EL2;
        EL.reserve(m * m); EL2.reserve(m * m);

        for (int i = 0; i < m-1; i++) {
            for (int j = i+1; j < m; j++){
                double dx = coordinates[i].first - coordinates[j].first;
                double dy = coordinates[i].second - coordinates[j].second;
                double distance = sqrt((dx*dx)+(dy*dy));
                if (distance > radius)
                    EL2.push_back({distance, i, j});
                else
                    EL.push_back({distance, i, j});
            }
        }
        
        sort(EL.begin(), EL.end());
        sort(EL2.begin(), EL2.end());

        UnionFind roads(m);

        double totalRoad = 0;
        int runs = 0;

        for(auto& [d, u, v] : EL) {
            if(roads.isSameSet(u, v)) continue;
            totalRoad += d;
            roads.unionSet(u, v);
            ++runs;
            if(runs == m-1) break;
        }
        int states = roads.numDisjointSets();

        double totalRail = 0;
        runs = 0;
        for(auto& [d, u, v] : EL2) {
            if(roads.isSameSet(u, v)) continue;
            totalRail += d;
            roads.unionSet(u, v);
            ++runs;
            if(runs == m-1) break;
        }

        cout << "Case #" << cases++ << ": " << states << " " << round(totalRoad) << " " << round(totalRail) << '\n';
    }

    return 0;
}
