#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, P, X, L;
    cin >> C >> P >> X >> L;
    
    X--; L--;
    
    vector<vector<int>> graph(C);
    vector<int> partners(C, 0);

    for (int i = 0; i < P; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
        partners[A]++;
        partners[B]++;
    }
    
    queue<int> q;
    vector<bool> inUnion(C, true);
    
    q.push(L);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        inUnion[current] = false;
        
        for (int neighbor : graph[current]) {
            if (!inUnion[neighbor]) continue;
            
            partners[neighbor]--;
            
            if (partners[neighbor] <= graph[neighbor].size()/2) {
                q.push(neighbor);
            }
        }
    }
    
    if (inUnion[X]) {
        cout << "stay" << endl;
    } else {
        cout << "leave" << endl;
    }
    
    return 0;
}
