#include <bits/stdc++.h>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int i = 0; i < 5; i++) {
            int menor = min(a, b);
            menor = min(menor, c);
            if(menor == a) a++;
            else if (menor == b) b++;
            else if(menor == c) c++;
        }

        cout << a*b*c << endl;        
    }
    
    return 0;
}
