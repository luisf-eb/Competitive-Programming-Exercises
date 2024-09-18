#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 0x3F3F3F3F
#define ll long long
#define ii pair<int, int>
#define vi vector<int>

int main() { fastio;

    int n; cin >> n;
    multiset<int> karamells;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        karamells.insert(x);
        sum += x;
    }
    
    if(sum%2) {
        cout << -1 << '\n';
        return 0;
    }
    
    //sort(karamells.begin(), karamells.end());
    vector<multiset<int>> conjunto(sum/2 + 1);
    vi change(sum/2 + 1, 0);
    
    change[0] = 1;

    for(auto& coin : karamells) {
        for (int i = change.size() - 1; i >= 0; i--) {
            // if(i == change.size() - 1)
            //     cout << "Coin: " << coin << " | change: " << i << " | i - coin: " << i-coin << "\n";
            if(i - coin < 0) break;
            if(change[i-coin] == 1) {
                // if(i == change.size() - 1)
                //     cout << "Formou troco\n";
                change[i] = 1;
                conjunto[i] = conjunto[i-coin];
                conjunto[i].insert(coin);
            }
            //cout << "\n";
        }
    }

    if(!change[sum/2]) {
        cout << -1 << '\n';
        return 0;
    }

    multiset<int> set1(conjunto[sum/2]), set2;

    set_difference(karamells.begin(), karamells.end(), set1.begin(), set1.end(), inserter(set2, set2.begin()));

    vi res;
    int bob = 0, alice = 0;
    auto it1 = set1.begin(), it2 = set2.begin();
    while (it1 != set1.end() || it2 != set2.end()) {
        if(it1 == set1.end()) {
            res.push_back(*it2);
            ++it2;
            continue;
        }
        if(it2 == set2.end()) {
            res.push_back(*it1);
            ++it1;
            continue;
        }
        
        if(bob < alice) {
            bob += *it1;
            res.push_back(*it1);
            ++it1;    
        } else {
            alice += *it2;
            res.push_back(*it2);
            ++it2;     
        }
    }
    
    for(auto& elem : res) cout << elem << " ";
    cout << '\n';

    return 0;
}