#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge{
    ll s, e, x;
    bool operator < (const Edge &edge) const { return x < edge.x; }
};

int N, M, P[10101];
vector<Edge> edges;

int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
bool Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return false;
    P[u] = v; return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M; edges.resize(M);
    for(auto &edge : edges) cin >> edge.s >> edge.e >> edge.x;
    sort(edges.begin(), edges.end());

    iota(P+1, P+N+1, 1);
    ll ans = 0;
    for(auto edge : edges) if(Merge(edge.s, edge.e)) ans += edge.x;
    cout << ans;
}
