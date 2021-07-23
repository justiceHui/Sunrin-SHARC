#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll M, N, A[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> M >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    ll l = 0, r = 2e9 + 10;
    while(l < r){
        ll m = l + r >> 1;
        ll require = accumulate(A+1, A+N+1, 0LL, [&m](ll a, ll b){ return a + max(0LL, b - m); });
        if(require <= M) r = m;
        else l = m + 1;
    }
    for(int i=1; i<=N; i++){
        M -= max(0LL, A[i] - r);
        A[i] = min(A[i], r);
    }

    priority_queue<ll> pq;
    for(int i=1; i<=N; i++) if(A[i]) pq.push(A[i]);
    for(int i=0; i<M && !pq.empty(); i++){
        ll now = pq.top(); pq.pop();
        if(now - 1 > 0) pq.push(now - 1);
    }

    ull ans = 0;
    while(pq.size()){
        ull now = pq.top(); pq.pop();
        ans += now * now;
    }
    cout << ans;
}
