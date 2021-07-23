#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SZ = 1 << 20;

int N, M, K;
ll A[SZ], T[SZ << 1];

void Build(){
    for(int i=1; i<=N; i++) T[i|SZ] = A[i];
    for(int i=SZ-1; i>=1; i--) T[i] = T[i << 1] + T[i << 1 | 1];
}

void Update(int x, ll v){
    x |= SZ; T[x] = v;
    while(x >>= 1) T[x] = T[x << 1] + T[x << 1 | 1];
}

ll Query(int l, int r){
    l |= SZ; r |= SZ;
    ll ret = 0;
    while(l <= r){
        if(l & 1) ret += T[l++];
        if(~r & 1) ret += T[r--];
        l >>= 1; r >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    Build();
    for(int i=1; i<=M+K; i++){
        ll op, a, b; cin >> op >> a >> b;
        if(op == 1) Update(a, b);
        else cout << Query(a, b) << "\n";
    }
}
