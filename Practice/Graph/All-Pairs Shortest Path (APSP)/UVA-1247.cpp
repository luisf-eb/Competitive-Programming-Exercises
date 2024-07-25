#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

void printPath(int i, int j, vector<vector<int>>& p) {
    if(i == j) {
        putchar(i + 'A');
        return;
    }
    printPath(i, p[i][j], p);
    printf(" %c", j + 'A');
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    int s, p;
    cin >> s >> p;

    vector<vector<int>> AM(s, vector<int>(s, INF)), parent(s, vector<int>(s));
    
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            parent[i][j] = i;
        }
    }

    while (p--) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        AM[u - 'A'][v - 'A'] = w;
        AM[v - 'A'][u - 'A'] = w;
    }

    for (int k = 0; k < s; k++) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (AM[i][j] > AM[i][k] + AM[k][j]) {
                    AM[i][j] = AM[i][k] + AM[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    int queries;
    cin >> queries;

    while (queries--) {
        char i, j;
        cin >> i >> j;
        printPath(i - 'A', j - 'A', parent);
        puts("");
    }

    return 0;
}
