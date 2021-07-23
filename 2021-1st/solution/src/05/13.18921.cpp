#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

struct Edge{
    ll s, e, x;
    bool operator < (const Edge &edge) const { return x < edge.x; }
    bool operator > (const Edge &edge) const { return x > edge.x; }
};

int N, P[101010], S[101010];
vector<Edge> edges;

int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
bool Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return false;
    P[u] = v; S[v] += S[u];
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; edges.resize(N - 1);
    for(auto &i : edges) cin >> i.s >> i.e >> i.x;
    sort(all(edges), greater<>());

    iota(P+1, P+N+1, 1);
    fill(S+1, S+N+1, 1);
    ll mx = 0;
    for(auto i : edges){
        if(Merge(i.s, i.e)) mx = max(mx, i.x * (S[Find(i.s)] - 1));
    }
    cout << mx;
}
