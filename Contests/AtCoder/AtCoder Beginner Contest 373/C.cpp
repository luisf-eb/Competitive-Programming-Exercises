#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n; cin >> n;
    vi A, B;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        B.push_back(x);
    }  

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    cout << A[n-1] + B[n-1] << '\n';

    return 0;
}