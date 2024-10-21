#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n, h; cin >> n >> h;
    vi floorS(n/2), ceilS(n/2);

    for (int i = 0; i < n/2; i++) { cin >> floorS[i]; cin >> ceilS[i]; }

    sort(floorS.begin(), floorS.end());
    sort(ceilS.begin(), ceilS.end());

    // for(auto& elem : floorS) cout << elem << " ";
    // cout << "\n";
    // for(auto& elem : ceilS) cout << elem << " ";
    // cout << "\n";

    vi ans(h, 0);
    int mini = INF;
    
    for (int i = 1; i <= h; i++){
        auto it_ceil = lower_bound(ceilS.begin(), ceilS.end(), h - i + 1);
        auto it_floor = lower_bound(floorS.begin(), floorS.end(), i);

        int temp = distance(it_ceil, ceilS.end()) + distance(it_floor, floorS.end());

        ans[i-1] = temp;
        mini = min(mini, temp);
    }

    int count = 0;
    for(auto& x : ans) if(x == mini) count++;
    
    cout << mini << " " << count << "\n";

    return 0;
}