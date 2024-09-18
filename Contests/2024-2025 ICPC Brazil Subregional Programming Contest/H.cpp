#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> perm_N;

bool check_divisibility(string& M, string& N) {
    ll sum = 0, B = stoll(N, nullptr, 2);
    ll pow = 1;

    for (int i = M.size()-1; i >= 0; i--) {
        if(M[i] == '1') sum += pow%B;
        pow = (pow*2)%B;
    }
    
    return sum % B == 0;
}

void solve(string M, int idx) {
    if (idx == M.size()) {
        //cout << M << '\n';
        for(auto& N : perm_N) {
            if (check_divisibility(M, N)) {
                cout << M << endl;
                exit(0);
            }
        }
        return;
    }

    if(M[idx] == '*') {
        M[idx] = '1';
        solve(M, idx+1);
        M[idx] = '0';
        solve(M, idx+1);
    } else solve(M, idx + 1);

}

void generateNs(string N, int idx) {
    if(idx == N.size()) {
        perm_N.push_back(N);
        return;
    }
 
    if(N[idx] == '*') {
        N[idx] = '0';
        generateNs(N, idx + 1);
        N[idx] = '1';
        generateNs(N, idx + 1);
    } else generateNs(N, idx +1 );
}

int main() {
    string M, N;
    cin >> M >> N;
    
    generateNs(N, 0);
    //for(auto& elem : perm_N) cout << elem << " ";
    solve(M, 0);

    return 0;
}
