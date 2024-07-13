#include <bits/stdc++.h>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin >> t;

    while(t--) {
        int n, k, x, maior = 0;
        cin >> n >> k;

        vector<int> pieces;
        int steps = 0;
        for (int i = 0; i < k; ++i) {
            cin >> x;
            pieces.push_back(x);
            maior = max(maior, x);
            if(x == 1) steps++;
            else steps += (x-1) + x;
        }

        if(maior == 1) steps--;
        else steps -= (maior-1) + maior;
        cout << steps << endl;
    }

    return 0;
}
