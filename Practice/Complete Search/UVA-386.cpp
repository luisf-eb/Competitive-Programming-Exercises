#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    for (int a = 1; a <= 200; a++) 
        for (int b = 2; b < a; b++) 
            for (int c = b + 1; c < a; c++) 
                for (int d = c + 1; d < a; d++) 
                    if( (a*a*a) == (b*b*b) + (c*c*c) + (d*d*d) ) 
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";

    return 0;
}