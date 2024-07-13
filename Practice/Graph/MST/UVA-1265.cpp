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
    int t, m, n;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        vector<tuple<int, int, int>> EL; EL.reserve(m);
        set<set<int>> islandsSet;
        int total = 0;

        while (m--) {
            int u, v, k;
            cin >> u >> v >> k;
            u--; v--;
            EL.push_back({k, u, v});
        }

        sort(EL.begin(), EL.end());
        
        int m = EL.size();
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            int x = get<1>(EL[i]); int y = get<2>(EL[i]);
            if(uf.isSameSet(x, y)) continue;

            uf.unionSet(x, y);
            
            

        }
        cout << total << '\n';
    }
    return 0;
}
