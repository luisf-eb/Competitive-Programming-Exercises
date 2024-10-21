#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { 
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int n, q, h; cin >> n;
    vi vec(n);

    for(auto& x : vec) cin >> x;

    cin >> q;
    while (q--) {
        cin >> h;
        
        int shortest = -1;
        int i = 0, j = n-1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if(vec[mid] >= h) j = mid - 1;
            if(vec[mid] < h) { shortest = vec[mid]; i = mid + 1; }
        }
        
        int tallest = -1;
        i = 0, j = n-1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if(vec[mid] > h) { tallest = vec[mid]; j = mid - 1;}
            if(vec[mid] <= h) i = mid + 1;
        }


        if(shortest == -1) cout << "X ";
        else cout << shortest << " ";

        if(tallest == -1) cout << "X\n";
        else cout << tallest << '\n';
    }
    

    return 0;
}
