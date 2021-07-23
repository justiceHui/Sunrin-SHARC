#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;
constexpr int SZ = 1 << 17;
constexpr int MAX_N = 101010, MAX_M = 202020;
constexpr int MAX_V = SZ*2 + MAX_M;

int N, S, M, A[MAX_N], In[MAX_V], D[MAX_V];
vector<PII> G[MAX_V];

void Init(){
    for(int i=1; i<SZ; i++){
        G[i<<1].emplace_back(i, 0);
        G[i<<1|1].emplace_back(i, 0);
    }
    for(int i=1; i<=S; i++){
        int x, y; cin >> x >> y; A[x] = y;
        G[0].emplace_back(x|SZ, y);
    }
}

vector<int> Range(int l, int r){
    l |= SZ; r |= SZ;
    vector<int> ret;
    while(l <= r){
        if(l & 1) ret.push_back(l++);
        if(~r & 1) ret.push_back(r--);
        l >>= 1; r >>= 1;
    }
    return move(ret);
}

void addEdge(int l, int r, int x){
    for(const auto &i : Range(l, r)) G[i].emplace_back(x, 0);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> S >> M; Init();

    for(int i=1; i<=M; i++){
        int l, r, k; cin >> l >> r >> k;
        for(int j=1; j<=k; j++){
            int t; cin >> t;
            G[SZ*2+i].emplace_back(t|SZ, 1);
            if(l < t) addEdge(l, t-1, SZ*2+i);
            l = t + 1;
        }
        if(l <= r) addEdge(l, r, SZ*2+i);
    }
    for(int i=0; i<MAX_V; i++) for(auto j : G[i]) In[j.x]++;

    queue<int> q;
    for(int i=0; i<MAX_V; i++){
        if(!In[i]) q.push(i);
        if(i) D[i] = 1;
    }
    while(q.size()){
        int v = q.front(); q.pop();
        for(auto i : G[v]){
            D[i.x] = max(D[i.x], D[v] + i.y);
            if(!--In[i.x]) q.push(i.x);
        }
    }

    for(int i=1; i<=N; i++){
        if(In[i|SZ] || D[i|SZ] > 1e9){ cout << "NIE"; return 0; }
        if(A[i] && A[i] != D[i|SZ]){ cout << "NIE"; return 0; }
    }
    cout << "TAK\n";
    for(int i=1; i<=N; i++) cout << D[i|SZ] << " ";
}
