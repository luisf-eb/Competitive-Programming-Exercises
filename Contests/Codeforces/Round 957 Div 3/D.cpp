#include <bits/stdc++.h>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        string river;
        cin >> n >> m >> k >> river;

        river = 'L' + river + 'L';
        int curr = 0, sz = river.size();

        while (curr < sz - 1) {
            if(river[curr] == 'C') break;

            if(river[curr] == 'L') {
                int jumped = 0;
                for (int i = min(m, sz - curr - 1); i >= 1; i--) {
                    if(river[curr+i] == 'L') {
                        curr = curr + i;
                        jumped = 1;
                        break;
                    }
                }
                
                if(!jumped) {
                    jumped = 0;
                    for (int i = min(m, sz - curr - 1); i >= 1; i--) {
                        if(river[curr+i] == 'W') {
                            curr += i;
                            jumped = 1;
                            break;
                        }
                    }
                }

                if(!jumped) break;
            }

            if(river[curr] == 'W') {
                if(k == 0) break;
                k--;
                curr++;
            }
        }
        
        if(curr == sz-1) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
