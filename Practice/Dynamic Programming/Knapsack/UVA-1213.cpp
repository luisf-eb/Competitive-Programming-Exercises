#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll int
#define ii pair<int, int>
#define vi vector<int>

ll _sieve_size;
bitset<10000010> bs;
vector<ll> p;
// 10^7 is the rough limit
// compact list of primes
void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; ++i)
        if (bs[i])
        {
            for (ll j = i * i; j < _sieve_size; j += i)
                bs[j] = 0;
            p.push_back(i);
        }
}

int memo[200][1121][15];
int dp(int i, int W, int k) {
    if (k == 0) return W == 0 ? 1 : 0;
    if (i >= (int)p.size() || p[i] > W) return 0; 
    if (memo[i][W][k] != -1) return memo[i][W][k];

    return memo[i][W][k] = dp(i + 1, W, k) + dp(i + 1, W - p[i], k - 1);
}

int main() { 
    fastio;

    sieve(1500);
    memset(memo, -1, sizeof memo);

    int n, k;
    while (cin >> n >> k) {
        if (!n && !k) break;
        cout << dp(0, n, k) << "\n";
    }

    return 0;
}
