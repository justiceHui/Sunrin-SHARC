#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;
vector<int> Inp[101010], G[101010];

ll T[1 << 18], L[1 << 18];
void Push(int node, int s, int e){
    T[node] += (e - s + 1) * L[node];
    if(s != e) L[node<<1] += L[node], L[node<<1|1] += L[node];
    L[node] = 0;
}
void Update(int l, int r, int v, int node=1, int s=1, int e=N){
    Push(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){ L[node] += v; Push(node, s, e); return; }
    int m = s + e >> 1;
    Update(l, r, v, node<<1, s, m);
    Update(l, r, v, node<<1|1, m+1, e);
    T[node] = T[node<<1] + T[node<<1|1];
}
ll Query(int l, int r, int node=1, int s=1, int e=N){
    Push(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return T[node];
    int m = s + e >> 1;
    return Query(l, r, node<<1, s, m) + Query(l, r, node<<1|1, m+1, e);
}
int Kth(ll k, int node=1, int s=1, int e=N){
    Push(node, s, e);
    if(s == e) return s;
    int m = s + e >> 1;
    Push(node<<1, s, m); Push(node<<1|1, m+1, e);
    if(k <= T[node<<1]) return Kth(k, node<<1, s, m);
    else return Kth(k-T[node<<1], node<<1|1, m+1, e);
}

int D[101010], P[22][101010], S[101010], Top[101010];
int In[101010], Out[101010], Rev[101010], pv;

void DFS(int v, int b=-1){
    for(auto i : Inp[v]){
        if(i == b) continue;
        D[i] = D[v] + 1; P[0][i] = v;
        G[v].push_back(i);
        DFS(i, v);
    }
}
void DFS1(int v){
    S[v] = 1;
    for(auto &i : G[v]){
        DFS1(i); S[v] += S[i];
        if(S[i] > S[G[v][0]]) swap(G[v][0], i);
    }
}
void DFS2(int v){
    In[v] = ++pv; Rev[pv] =v;
    for(auto i : G[v]){
        Top[i] = i == G[v][0] ? Top[v] : i;
        DFS2(i);
    }
    Out[v] = pv;
}

ll Total;
void UpdateSub(int v){
    Update(In[v], Out[v], 1);
    Total += Out[v] - In[v] + 1;
}
void UpdatePath(int u, int v){
    for(; Top[u] != Top[v]; u=P[0][Top[u]]){
        if(D[Top[u]] < D[Top[v]]) swap(u, v);
        Update(In[Top[u]], In[u], 1);
        Total += In[u] - In[Top[u]] + 1;
    }
    if(D[u] > D[v]) swap(u, v);
    Update(In[u], In[v], 1);
    Total += In[v] - In[u] + 1;
}
int Query(){
    int v = Rev[Kth((Total + 1) / 2)];
    if(Query(In[v], Out[v]) * 2 > Total) return v;
    for(int i=21; ~i; i--){
        if(!P[i][v]) continue;
        if(Query(In[P[i][v]], Out[P[i][v]]) * 2 <= Total) v = P[i][v];
    }
    return P[0][v];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<N; i++){
        int s, e; cin >> s >> e;
        Inp[s].push_back(e); Inp[e].push_back(s);
    }
    DFS(1); DFS1(1); DFS2(Top[1]=1);
    for(int i=1; i<22; i++) for(int j=1; j<=N; j++) P[i][j] = P[i-1][P[i-1][j]];

    cin >> Q;
    while(Q--){
        int op, a, b; cin >> op >> a;
        if(op == 1) UpdateSub(a);
        else cin >> b, UpdatePath(a, b);
        cout << Query() << "\n";
    }
}
