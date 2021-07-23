#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;

int N, M, S, T, D[1010];
vector<PLL> G[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int s, e, x; cin >> s >> e >> x;
        G[s].emplace_back(e, x);
    }
    cin >> S >> T;

    priority_queue<PLL, vector<PLL>, greater<>> pq;
    memset(D, 0x3f, sizeof D);
    pq.emplace(0, S); D[S] = 0;
    while(pq.size()){
        auto [cst,v] = pq.top(); pq.pop();
        if(cst > D[v]) continue;
        for(auto i : G[v]){
            if(D[i.x] > cst + i.y) pq.emplace(D[i.x] = cst + i.y, i.x);
        }
    }
    cout << D[T];
}
