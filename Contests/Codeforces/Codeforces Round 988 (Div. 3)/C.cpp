#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

ll _sieve_size;
bitset<10000010> bs;
vector<ll> p;
void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    // 10^7 is the rough limit
    // compact list of primes
    // range = [0..upperbound]
    // to include upperbound
    // all 1s
    // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i)
        if (bs[i])
        {
            // cross out multiples of i starting from i*i
            for (ll j = i * i; j < _sieve_size; j += i)
                bs[j] = 0;
            p.push_back(i);
            // add prime i to the list
        }
}
bool isPrime(ll N)
{
    if (N < _sieve_size)
        return bs[N];
    // good enough prime test
    // O(1) for small primes
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
        if (N % p[i] == 0)
            return false;
    return true;
    // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

int main() { fastio;

    sieve(1000000);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vi even, odds;
        for (int i = 1; i <= n; i++) {
            if(!(i%2)) even.push_back(i);
            else odds.push_back(i);
        }
        
        int i = 0;
        while (i < odds.size() && isPrime(even.back() + odds[i])) ++i;
        if(i == odds.size()) {
            cout << -1 << '\n';
            continue;
        }
        swap(odds[i], odds[0]);
        
        for(auto& x : even) cout << x << " ";
        for (int i = 0; i < odds.size(); i++) {
            if(i == odds.size() - 1) cout << odds[i] << "\n";
            else cout << odds[i] << " ";
        }
        
    }
    

    return 0;
}