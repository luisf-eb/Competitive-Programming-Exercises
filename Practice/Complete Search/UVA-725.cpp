#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { //fastio;

    int n;
    int cont = 0;
    while (cin >> n && n) {
        if(cont++) printf("\n");

        bool flag = 0;
        for (int b = 1234; b <= 98765/n; b++) {
            int a = b*n;
            int temp, used = (b < 10000);
            temp = b; while (temp) { used |= 1<<(temp%10); temp /= 10; };
            temp = a; while (temp) { used |= 1<<(temp%10); temp /= 10; };
            
            if(used == (1<<10) - 1) {
                flag = 1;
                printf("%05d / %05d = %d\n", a, b, n);
            }
        }
        
        if(!flag) printf("There are no solutions for %d.\n", n);
    }
    

    return 0;
}