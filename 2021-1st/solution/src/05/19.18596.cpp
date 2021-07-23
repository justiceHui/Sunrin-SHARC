#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Info{
    ll a, b, idx;
    Info() : Info(0, 0, 0) {}
    Info(ll a, ll b, ll idx) : a(a), b(b), idx(idx) {}
    bool operator < (const Info &t) const {
        ll le = b - a, ri = t.b - t.a;
        if(le >= 0 && ri < 0) return false;
        if(le < 0 && ri >= 0) return true;
        if(le < 0 && ri < 0) return b < t.b;
        if(le >= 0 && ri >= 0) return a > t.a;
        return idx < t.idx;
    }
    Info& operator += (const Info &t){
        ll down = min(-a, -a + b - t.a);
        ll final = -a + b - t.a + t.b;
        this->a = -down;
        this->b = final - down;
        return *this;
    }
};

int N, UF[101010], P[101010], C[101010];
Info A[101010];
vector<int> G[101010];
priority_queue<Info> pq;

void Clear(){
    iota(UF+1, UF+N+1, 1);
    memset(C+1, 0, sizeof(C[0]) * N);
    for(int i=1; i<=N; i++) G[i].clear();
}

int Find(int v){ return v == UF[v] ? v : UF[v] = Find(UF[v]); }

void DFS(int v, int b=-1){
    for(auto i : G[v]) if(i != b) P[i] = v, DFS(i, v);
}

void Solve(){
    cin >> N; Clear();
    A[1] = {0, 0, 1};
    for(int i=2; i<=N; i++){
        cin >> A[i].a >> A[i].b; A[i].idx = i;
        pq.push(A[i]);
    }
    for(int i=1; i<N; i++){
        int s, e; cin >> s >> e;
        G[s].push_back(e); G[e].push_back(s);
    }
    DFS(1);

    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int now = t.idx, nxt = Find(P[now]);
        if(C[now]) continue; C[now] = 1;
        A[nxt] += A[now]; UF[now] = nxt;
        if(nxt != 1) pq.push(A[nxt]);
    }
    cout << A[1].a << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++) Solve();
}
