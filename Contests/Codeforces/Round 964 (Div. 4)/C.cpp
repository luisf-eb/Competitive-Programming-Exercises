#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

int main() { fastio;

    int tc;
    cin >> tc;

    while(tc--){
        int n, m, s;
        cin >> n >> s >> m;
        vector<ii> intervals;

        intervals.push_back({0, 0});

        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            intervals.push_back({u, v});
        }  
        intervals.push_back({m, m});

        int flag = 0;
        for (int i = 1; i <= n+1; i++) {
            int time = intervals[i].first - intervals[i-1].second;
            if(time >= s) {
                flag = 1;
                break;
            }
        }
        
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}