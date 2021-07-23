#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

int N, M;
vector<PLL> G[5050];
vector<int> Start;
int W1[5050], W2[5050];
ll D[2][5050];

void Dijkstra(ll dst[5050], priority_queue<PLL, vector<PLL>, greater<>> &pq){
    while(pq.size()){
        auto [cst,v] = pq.top(); pq.pop();
        if(cst > dst[v]) continue;
        for(auto i : G[v]){
            if(dst[i.x] > cst + i.y) pq.emplace(dst[i.x] = cst + i.y, i.x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int s, e, x, y; cin >> s >> e >> x >> y;
        if(e == 1) swap(s, e), swap(x, y);
        if(s == 1) Start.push_back(e), W1[e] = x, W2[e] = y;
        else G[s].emplace_back(e, x), G[e].emplace_back(s, y);
    }

    ll mn = INF;
    priority_queue<PLL, vector<PLL>, greater<>> Q[2];

    for(int bit=0; bit<13; bit++){
        memset(D, 0x3f, sizeof D);
        for(auto i : Start){
            if(i & (1 << bit)) D[0][i] = W1[i], Q[0].emplace(W1[i], i);
            else D[1][i] = W2[i], Q[1].emplace(W1[i], i);
        }
        Dijkstra(D[0], Q[0]);
        Dijkstra(D[1], Q[1]);
        for(auto i : Start){
            if(i & (1 << bit)) mn = min(mn, D[1][i] + W2[i]);
            else mn = min(mn, D[0][i] + W2[i]);
        }
    }
    cout << mn;
}
