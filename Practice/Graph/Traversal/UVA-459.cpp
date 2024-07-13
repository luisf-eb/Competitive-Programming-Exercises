#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

vector<int> visited;

void bfs(int i, vector<vector<int>>& grafo) {
    visited[i] = 1;
    for (auto& x : grafo[i]) {
        if (!visited[x]) bfs(x, grafo);
    }
}

int main() {
    fastio;
    int n;
    string entrada;

    getline(cin, entrada);
    n = stoi(entrada);
    getline(cin, entrada);

    while (n--) {
        getline(cin, entrada);
        char letter = entrada[0];
        int tam = letter - 'A' + 1;
        vector<vector<int>> grafo(tam);

        while (getline(cin, entrada)) {
            if (entrada.empty()) break; // Break if the line is empty
            int letra1 = entrada[0] - 'A';
            int letra2 = entrada[1] - 'A';
            grafo[letra1].push_back(letra2);
            grafo[letra2].push_back(letra1);
        }

        visited.assign(tam, 0);
        int contador = 0;
        for (int i = 0; i < tam; i++) {
            if (!visited[i]) {
                bfs(i, grafo);
                contador++;
            }
        }
        cout << contador << '\n';
        if (n) cout << '\n';
    }

    return 0;
}
