#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<long long, int> seen;
        long long sum = 0;
        int ans = 0;
        int last_end = -1;

        seen[0] = -1;
        
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (seen.find(sum) != seen.end()) {
                if (seen[sum] >= last_end) {
                    ans++;
                    last_end = i;
                }
            }
            seen[sum] = i;
        }

        cout << ans << endl;
    }

    return 0;
}
