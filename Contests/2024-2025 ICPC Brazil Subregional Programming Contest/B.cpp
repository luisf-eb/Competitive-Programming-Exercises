    #include <bits/stdc++.h>
    using namespace std;
     
    /* TYPES */
    #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
    #define INF 0x3F3F3F3F
    #define ll long long
    #define ii pair<int, int>
    #define vi vector<int>
    #define TAM 103
     
    int AM[TAM][TAM], p[TAM][TAM], AM2[TAM][TAM];
     
    int main() { fastio;
     
        int n, m; cin >> n >> m;
        vector<vector<int>> actorsMovies(m+1);
        memset(AM2, 0, sizeof(AM2));
     
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AM[i][j] = INF;
                p[i][j] = i;
            }
            AM[i][i] = 0;
        }
            
        for (int k = 0; k < n; k++){
            int x; cin >> x;
            while (x--) {
                int u; cin >> u;
                u;
                for(auto& elem : actorsMovies[u]) {
                    if(!AM2[k][elem]) {
                        AM[k][elem] = 1;
                        AM[elem][k] = 1;
                        AM2[elem][k] = u;
                        AM2[k][elem] = u;
                    }
                }

                actorsMovies[u].push_back(k);
            }
            
        }
     
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if(AM[i][k] + AM[k][j] < AM[i][j]) {
                        AM[i][j] = AM[i][k] + AM[k][j];
                        p[i][j] = p[k][j];
                    }
                }
            }
        }

        int queries; cin >> queries;
        while (queries--) {
            int v, u; cin >> v >> u;
            
            int menorDist = INF, found = 0, s, e;
            for(auto& filmeS : actorsMovies[v]) {
                for(auto& filmeE : actorsMovies[u]) {
                    if(filmeS == filmeE) {
                        menorDist = 0;
                        s = e = filmeS;
                        found = 1;
                        break;
                    }

                    if(AM[filmeS][filmeE] < menorDist) {
                        s = filmeS;
                        e = filmeE;
                        menorDist = AM[filmeS][filmeE];
                    }
                }

                if(found) break;
            }
            
            if(menorDist == INF) {
                cout << -1 << '\n';
                continue;
            }
            
            int ans = 2;
            if(s == e) {
                cout << ans << '\n';
                cout << v << " " << s+1 << " " << u << '\n';
                continue;
            }

            vi aux = {u};
            while (e != s) {
                aux.push_back(e+1);
                aux.push_back(AM2[p[s][e]][e]);
                e = p[s][e];
                ++ans;
            }
            aux.push_back(e+1);
            aux.push_back(v);

            cout << ans << "\n";
            for(auto it = aux.rbegin(); it != aux.rend(); it++) {
                cout << *it << ' ';
            }
            cout << "\n";
        }
        
     
        return 0;
    }