#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using PLL = pair<ll, ll>;

int N, K;
ll A[50505], D[50505], C[50505];

int T[1 << 17];
inline ll f(int i, int j){
    return D[i] + (A[j] - A[i]) * (j - i);
}

void update(int hi){
    int node = 1, s = 1, e = N;
    while(s <= e){
        int m = s + e >> 1;
        int &lo = T[node];
        if(f(hi, s) < f(lo, s)) swap(lo, hi);
        if(f(lo, e) < f(hi, e)) break;
        if(f(lo, m) <= f(hi, m)) node = node << 1 | 1, s = m + 1;
        if(f(hi, m) < f(lo, m)) swap(lo, hi), node = node << 1, e = m - 1;
    }
}

int query(int x){
    int node = 1, s = 1, e = N, line = 0;
    while(s <= e){
        int m = s + e >> 1;
        if(f(T[node], x) < f(line, x)) line = T[node];
        if(x < m) node = node << 1, e = m - 1;
        else if(x > m) node = node << 1 | 1, s = m + 1;
        else break;
    }
    return line;
}

PLL Solve(ll cost){
    memset(T, 0, sizeof T);
    for(int i=1; i<=N; i++){
        int prv = query(i);
        D[i] = f(prv, i) + cost;
        C[i] = C[prv] + 1;
        update(i);
    }
    return {D[N], C[N]};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    partial_sum(A+1, A+N+1, A+1);

    ll l = 0, r = 1e15;
    while(l < r){
        ll m = l + r >> 1;
        if(Solve(m).second <= K) r = m;
        else l = m + 1;
    }
    cout << Solve(r).first - r * K;
}
