#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;

int N, Q, P[22][101010], D[101010];
ll C[101010];
vector<PLL> G[101010];

void DFS(int v, int b=-1){
    for(auto i : G[v]){
        if(i.x == b) continue;
        P[0][i.x] = v;
        D[i.x] = D[v] + 1;
        C[i.x] = C[v] + i.y;
        DFS(i.x, v);
    }
}

int LCA(int u, int v){
    if(D[u] < D[v]) swap(u, v);
    int diff = D[u] - D[v];
    for(int i=0; diff; i++, diff>>=1) if(diff & 1) u = P[i][u];
    if(u == v) return u;
    for(int i=21; ~i; i--) if(P[i][u] != P[i][v]) u = P[i][u], v = P[i][v];
    return P[0][u];
}
ll Dist(int u, int v){ return C[u] + C[v] - 2 * C[LCA(u, v)]; }

int Kth(int u, int v, int k){
    int l = LCA(u, v); k--;
    if(k > D[u] - D[l]){
        k = D[v] - D[l] - k + D[u] - D[l];
        u = v;
    }
    for(int i=0; k; i++, k>>=1) if(k & 1) u = P[i][u];
    return u;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<N; i++){
        int s, e, x; cin >> s >> e >> x;
        G[s].emplace_back(e, x);
        G[e].emplace_back(s, x);
    }
    DFS(1);
    for(int i=1; i<22; i++) for(int j=1; j<=N; j++) P[i][j] = P[i-1][P[i-1][j]];

    cin >> Q;
    while(Q--){
        int op, a, b, c; cin >> op >> a >> b;
        if(op == 1) cout << Dist(a, b) << "\n";
        else cin >> c, cout << Kth(a, b, c) << "\n";
    }
}
