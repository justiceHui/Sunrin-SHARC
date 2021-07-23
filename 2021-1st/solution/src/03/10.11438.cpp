#include <bits/stdc++.h>
using namespace std;

int N, Q, D[101010], P[22][101010];
vector<int> G[101010];

void DFS(int v, int b=-1){
    for(auto i : G[v]){
        if(i == b) continue;
        D[i] = D[v] + 1; P[0][i] = v;
        DFS(i, v);
    }
}

int LCA(int u, int v){
    if(D[u] < D[v]) swap(u, v);
    int diff = D[u] - D[v];
    for(int i=0; diff; i++, diff>>=1) if(diff & 1) u = P[i][u];
    if(u == v) return u;
    for(int i=21; i>=0; i--) if(P[i][u] != P[i][v]) u = P[i][u], v = P[i][v];
    return P[0][u];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<N; i++){
        int s, e; cin >> s >> e;
        G[s].push_back(e); G[e].push_back(s);
    }
    DFS(1);
    for(int i=1; i<22; i++) for(int j=1; j<=N; j++) P[i][j] = P[i-1][P[i-1][j]];
    cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
}
