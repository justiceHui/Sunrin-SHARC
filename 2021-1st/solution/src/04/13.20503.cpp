#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;
constexpr int MX_BIT = 28;

int N, A[202020], S[202020];
vector<int> G[202020];

int get_sz(int v, int b=-1){
    S[v] = 1;
    for(auto i : G[v]) if(i != b) S[v] += get_sz(i, v);
    return S[v];
}

PII get_edge(int v, int total, int b=-1){
    int now = abs(total - S[v]*2);
    PII ret(b, v);
    for(auto i : G[v]){
        if(i == b) continue;
        PII t = get_edge(i, total, v);
        int nxt = abs(total - S[t.y]*2);
        if(nxt < now) now = nxt, ret = t;
    }
    return ret;
}

void get_vertices(int v, vector<int> &lst, int b=-1){
    lst.push_back(v);
    for(auto i : G[v]) if(i != b) get_vertices(i, lst, v);
}

void Solve(int v, int base=0, int dep=MX_BIT){
    if(get_sz(v) == 1){
        if(A[v] == -1) A[v] = base;
        return;
    }
    auto [s,e] = get_edge(v, S[v]);
    G[s].erase(find(G[s].begin(), G[s].end(), e));
    G[e].erase(find(G[e].begin(), G[e].end(), s));

    vector<int> vertices; get_vertices(e, vertices);
    Solve(s, base, dep-1);
    Solve(e, base | (1 << dep), dep-1);

    int color = A[s] ^ A[e] ^ (1 << dep);
    for(auto i : vertices) A[i] ^= color;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<N; i++){
        int s, e; cin >> s >> e;
        G[s].push_back(e); G[e].push_back(s);
    }
    memset(A, -1, sizeof A);
    Solve(1);
    for(int i=1; i<=N; i++) cout << A[i] << " ";
}
