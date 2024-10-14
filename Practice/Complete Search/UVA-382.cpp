#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n;

    cout << "PERFECTION OUTPUT\n";
    while (cin >> n) {
        if(n == 0) { cout << "END OF OUTPUT\n"; break; };
        
        int sum = 0;

        for (int i = 1; i < n; i++) if( !(n%i) ) 
            sum += i;
        
        cout << setw(5) << right << n << "  ";
        if(sum < n) cout << "DEFICIENT\n";
        else if(sum > n) cout << "ABUNDANT\n";
        else cout << "PERFECT\n";
    }
    

    return 0;
}