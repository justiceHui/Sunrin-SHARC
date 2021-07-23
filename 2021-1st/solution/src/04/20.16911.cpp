#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

struct UnionFind{
    int P[101010], R[101010];
    UnionFind(){ iota(P, P+101010, 0); fill(R, R+101010, 1); }
    int find(int v){ return v == P[v] ? v : find(P[v]); }
    PII merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return {-1, -1};
        if(R[u] > R[v]) swap(u, v);
        P[u] = v;
        if(R[u] == R[v]) R[v]++;
        return {u, v};
    }
    void undo(int u, int v){
        P[u] = u;
        if(R[u]+1 == R[v]) R[v]--;
    }
} uf;

struct Query{
    int u, v, l, r;
    Query() = default;
    Query(int u, int v, int l, int r) : u(u), v(v), l(l), r(r) {}
};

int N, Q, pv = 1;
PII Check[101010];
map<PII, int> mp;
vector<Query> qry;
vector<PII> T[1 << 20];

void Add(int l, int r, PII edge, int node=1, int s=1, int e=pv-1){
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        T[node].push_back(edge); return;
    }
    int m = s + e >> 1;
    Add(l, r, edge, node<<1, s, m);
    Add(l, r, edge, node<<1|1, m+1, e);
}

void DFS(int node=1, int s=1, int e=pv-1){
    vector<PII> merged;
    for(auto i : T[node]) merged.push_back(uf.merge(i.x, i.y));
    if(s == e){
        if(uf.find(Check[s].x) == uf.find(Check[s].y)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    else{
        int m = s + e >> 1;
        DFS(node<<1, s, m);
        DFS(node<<1|1, m+1, e);
    }
    reverse(merged.begin(), merged.end());
    for(auto [u,v] : merged) if(u != -1) uf.undo(u, v);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    for(int i=1; i<=Q; i++){
        int op, a, b; cin >> op >> a >> b; if(a > b) swap(a, b);
        if(op == 1) mp[{a, b}] = pv;
        else if(op == 2) qry.emplace_back(a, b, mp[{a,b}], pv), mp.erase(PII(a,b));
        else if(op == 3) Check[pv++] = {a, b};
    }
    for(auto i : mp) qry.emplace_back(i.x.x, i.x.y, i.y, pv);
    for(auto i : qry) if(i.l < i.r) Add(i.l, i.r-1, {i.u, i.v});
    DFS();
}
