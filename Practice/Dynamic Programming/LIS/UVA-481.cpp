#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

vi p, A;

void print_LIS(int i) {
    if (p[i] == -1){
        cout << A[i] << '\n';
        return;
    }
    
    print_LIS(p[i]);

    cout << A[i] << '\n';
}

int main() { fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int x, k = 0, last = 0;

    while (cin >> x) A.push_back(x);

    int n = A.size();
    vi L(n, 0), L_id(n, 0);
    p.assign(n, -1);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;

        if(pos == k) {
            last = i;
            ++k;
        }
    }
    
    cout << k << "\n-\n";
    print_LIS(last);

    return 0;
}